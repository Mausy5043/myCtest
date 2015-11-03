#! /bin/bash

 git pull
 git fetch origin
 git checkout master
 git reset --hard origin/master && \
 git clean -f -d

chmod -R 744 *
