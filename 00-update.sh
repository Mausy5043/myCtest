#! /bin/bash

 git fetch origin
 git diff --name-only
 git log --graph --oneline --date-order --decorate --color --all |head -n 5

 git pull
 git fetch origin
 git checkout master
 git reset --hard origin/master && \
 #git clean -f -d

chmod -R 744 *
