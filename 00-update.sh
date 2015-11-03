#! /bin/bash

 git fetch origin
 git log --graph --oneline --date-order --decorate --color --all

 git pull
 git fetch origin
 git checkout master
 git reset --hard origin/master && \
 #git clean -f -d

chmod -R 744 *
