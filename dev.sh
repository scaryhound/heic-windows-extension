#!/bin/bash
echo "Building the Dev Container (few minutes waiting...)"
docker build -t heic-dev-env .
echo "Starting Container"
docker run -it --rm -v "$(pwd):/workspace" heic-dev-env
