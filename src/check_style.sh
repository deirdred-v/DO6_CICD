#!/bin/bash

FILES=$(find src/ -type f \( -name "*.c" -o -name "*.h" \))

for f in $FILES; do
    clang-format -style=file "$f" | diff "$f" - > /dev/null
    if [ $? -ne 0 ]; then
        echo "File $f does not conform to clang-format!"
        exit 1
    fi
done

exit 0

