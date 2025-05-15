mkcd () {
    mkdir "$1" && cd "$1"
}

build () {
    g++ "$1" -o "$(realpath "$1").exe" 2>&1
}

run () {
    if [ "$1" -nt "$(realpath "$1").exe" ]; then
        build "$1" && "$(realpath "$1").exe"
    else
        "$(realpath "$1").exe"
    fi
}

buildall () {
    for f in `find | grep \\.cpp$`; do
        echo -n "$f"
        build "$f" > "$f.log"
        if [ $? -eq 0 ]; then
            rm "$f.log"
            echo # add newline
        else
            echo " - error"
        fi
    done
}

clean () {
    for f in `find | grep "\\.log$\\|\\.exe$"`; do
        echo "$f"
        rm "$f"
    done
}

mkdir -p week1 week2 week3 week4 week5 week6