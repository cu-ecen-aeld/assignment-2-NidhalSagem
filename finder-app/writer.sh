#!/bin/bash

# Check if the required number of arguments are provided
if [ "$#" -ne 2 ]; then
    echo "Error: Missing arguments."
    echo "Usage: $0 <writefile> <writestr>"
    exit 1
fi

writefile="$1"
writestr="$2"

# Extract the directory path from the writefile argument
writedir=$(dirname "$writefile")

# Create the directory path if it doesn't exist
mkdir -p "$writedir"
if [ $? -ne 0 ]; then
    echo "Error: Could not create directory path '$writedir'."
    exit 1
fi

# Write the string to the file, overwriting any existing file
echo "$writestr" > "$writefile"
if [ $? -ne 0 ]; then
    echo "Error: Could not write to file '$writefile'."
    exit 1
fi

exit 0
