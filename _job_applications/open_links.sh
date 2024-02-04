#!/bin/bash
# replace the it with the location of the text file where links are present.
# File containing the URLs
FILE="links.txt"

# Check if the file exists
if [ ! -f "$FILE" ]; then
    echo "File not found: $FILE"
    exit 1
fi

# Read each line in the file
while IFS= read -r line; do
    # Open each URL in Google Chrome
    google-chrome "$line" &
done < "$FILE"
