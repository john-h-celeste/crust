# split an autograder .yml workflow with one job into one job for each test
# and one job to report the final results

import yaml
import copy

# read in the original workflow
with open(".github/workflows/classroom.yml") as f:
    data = yaml.load(f.read(), yaml.Loader)

# make sure there is exactly one job
assert len(data['jobs']) == 1

# assume the single job is called 'run-autograding-tests'
steps = data['jobs']['run-autograding-tests']['steps']

# the first step is always to checkout the code
assert steps[0] == {'name': 'Checkout code', 'uses': 'actions/checkout@v4'}

# and the last step is the autograding reporter
assert steps[-1]['name'] == 'Autograding Reporter'
assert steps[-1]['uses'] == 'classroom-resources/autograding-grading-reporter@v1'
assert steps[-1]['with'] == {'runners': ','.join(step['id'] for step in steps[1:-1])}

# `resultkeys` is a mapping from the step names to their keys in the autograding reporter
resultkeys = {}

# for every key the autograding reporter uses:
for k,v in steps[-1]['env'].items():
    # make sure it matches one of the steps
    assert any(v == f'${{{{steps.{step["id"]}.outputs.result}}}}' for step in steps[1:-1])
    resultkeys[[step['id'] for step in steps[1:-1] if v == f'${{{{steps.{step["id"]}.outputs.result}}}}'][0]] = k

# make a copy of the original workflow except for the jobs
new = copy.deepcopy(data)
new['jobs'] = {}

# make a copy of the original job except for the steps
job = copy.deepcopy(data['jobs']['run-autograding-tests'])
job['steps'] = [{'name': 'Checkout code', 'uses': 'actions/checkout@v4'}]

for step in steps[1:-1]:
    # check the step to see that it matches my expected format
    assert step['id'] == step['name']
    assert step['uses'] == 'classroom-resources/autograding-io-grader@v1'

    # make the job with this step and the autograding reporter reporting one score
    j = copy.deepcopy(job)
    j['steps'].append(step)
    j['steps'].append({
        'env': {resultkeys[step['name']]: f'${{{{steps.{step["name"]}.outputs.result}}}}'},
        'name': 'Autograding Reporter',
        'uses': 'classroom-resources/autograding-grading-reporter@v1',
        'with': {'runners': step["name"]}
    })

    # add an output so the final job can see the output
    j['outputs'] = {'result': f'${{{{steps.{step["name"]}.outputs.result}}}}'}

    # add this job to the list
    new['jobs'][f'run-autograding-{step["name"]}'] = j

# create the final job to report all the results
j = copy.deepcopy(job)

# it depends on all the others
j['needs'] = [f'run-autograding-{step["name"]}' for step in steps[1:-1]]

# add the autograding report step
j['steps'] = [{
    'name': 'Autograding Reporter',
    'uses': 'classroom-resources/autograding-grading-reporter@v1',
    # collect all the outputs into one
    'env': {resultkeys[step['name']]: f'${{{{needs.run-autograding-{step["name"]}.outputs.result}}}}' for step in steps[1:-1]},
    'with': {'runners': ','.join(step["name"] for step in steps[1:-1])}
}]

# add the job to the list
new['jobs']['autograding-report'] = j

# change the name
new['name'] += ' (auto reformatted)'

# write the new workflow to another file
with open(".github/workflows/classroom2.yml", "w") as f:
    yaml.dump(new, f, yaml.Dumper)