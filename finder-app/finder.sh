#!/usr/bin/env bash

filesdir=$1
searchstr=$2

[[ $# -ne 2 ]] && {
    echo 'You must specify 2 arguments.'
    exit 1
}

[[ -d "$filesdir" ]] || {
    echo "'$filesdir' is not a directory."
    exit 1
}

file_list=$(find "$filesdir" -type f)
file_num=$(wc -l <<< "$file_list")
line_num=$(xargs grep "$searchstr" <<< "$file_list" | wc -l )

echo "The number of files are $file_num and the number of matching lines are $line_num"
