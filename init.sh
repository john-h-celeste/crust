mkcd () {
    mkdir "$1" && cd "$1"
}

build () {
    g++ "$1" $(if [ -f "$1.dep" ]; then cat "$1.dep"|while read line; do echo "$(dirname "$1")/$line"; done; fi) -o "$1.exe" 2>&1
}

run () {
    if [ "$1" -nt "$1.exe" ]; then
        build "$1"
    else
        if [ -a "$1.dep" ]; then
            cat "$1.dep"|while read line; do 
                if [ "$(dirname "$1")/$line" -nt "$1.exe" ]; then
                    build "$1"
                    break
                fi
            done
        fi
    fi
    "$(realpath "$1").exe"
}

buildall () {
    for f in `find | grep \\.cpp$`; do
        if [ -f "$f.lib" ]; then
            :;
        else
            echo -n "$f"
            build "$f" > "$f.log"
            if [ $? -eq 0 ]; then
                rm "$f.log"
                echo # add newline
            else
                echo " - error"
            fi
        fi
    done
}

clean () {
    for f in `find | grep "\\.log$\\|\\.exe$"`; do
        echo "$f"
        rm "$f"
    done
}

day () {
    # the number of day folders that have been created
    ls -d */*/ | wc -l
}

mkdir -p 1 2 3 4 5 6