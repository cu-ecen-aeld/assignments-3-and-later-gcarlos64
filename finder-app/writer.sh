#!/usr/bin/env bash

writefile=$1
writestr=$2

[[ $# -ne 2 ]] && {
    echo 'You must specify 2 arguments.'
    exit 1
}

dir=$(dirname "$writefile")
mkdir -p "$dir" || { exit 1; }

echo "$writestr" > "$writefile"
