#!/bin/bash
gcc -Wall -Werror -Wextra  -pedantic -c -fPIC *.c
gcc -shared -o liball.so *.0
exprot LD_LIBRARY_PATH=.:$ LD_LIBRARY_PATH
