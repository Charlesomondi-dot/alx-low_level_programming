#!/bin/bash
o -e "#include <stdio.h>\n#include <stdlib.h>\nvoid srand(unsigned int seed) { (void) seed; }\nint rand(void) { return 6; }" > /tmp/rand.c
gcc -shared -o /tmp/rand.so /tmp/rand.c
LD_PRELOAD=/tmp/rand.so
