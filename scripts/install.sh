#!/usr/bin/env sh

dependencies=(gcc g++)

sudo apt-get update
for dependency in dependencies; do
  sudo apt-get install "$dependency"
done
