mkcd () {
    mkdir "$1" && cd "$1"
}

build () {
    g++ "$1" -o "$(realpath "$1").exe" && "$(realpath "$1").exe"
}