mkcd () {
    mkdir "$1" && cd "$1"
}

build () {
    g++ "$1" -o "$(realpath "$1").exe"
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
        echo "$f"
        build "$f"
    done
}