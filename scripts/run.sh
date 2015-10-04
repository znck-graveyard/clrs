#!/usr/bin/env sh

root="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
runners=("c++.sh")

for runner in $runners; do
  "$root/$runner"
done
