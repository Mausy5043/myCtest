#! /bin/bash

 git pull
 git fetch origin
 git checkout $branch
 git reset --hard origin/$branch && \
 git clean -f -d
