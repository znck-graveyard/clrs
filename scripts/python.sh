#!/bin/bash

echo "Testing CRLS python code"
# Create temporary directory
mkdir temp

root="$( dirname "$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )" )"
sources="${root}/python"
root_len=$(( ${#root} + 8 ))

# Select files.
files=$(find ${sources} -type f -name "*.py")
failed=0
count=0
passed=0

function infile() {
  f=${root}/tests/${1:$root_len}

  echo "${f%.*}/input.txt"
  return
}

function outfile() {
  f=${root}/tests/${1:$root_len}

  echo "${f%.*}/output.txt"
  return
}


for FILE in $files; do
  input=$(infile "$FILE")
  expected=$(outfile "$FILE")
  output="temp/expected.txt"
  # Running
  python "$FILE" < "$input" > "$output"
  check=$(diff -q $output $expected)
  if [ -z "$check" ]; then
    passed=$(( $passed + 1 ))
  else
    failed=$(( $failed + 1 ))
    printf '\e[1;31mTest Failed: \e[m%s\n' "${FILE}"
  fi
  count=$(( $count + 1 ))
done

# Remove temporary directory
rm -rf temp

# Check for errors
printf '\e[1;32mFinished running: \e[m%s\n' "${count} tests. ${passed} tests passed. ${failed} tests failed"
if [[ ${failed} -gt 0 ]]; then
  exit 1
else
  exit 0
fi
