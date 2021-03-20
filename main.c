#include <stdio.h>
#include <stdlib.h>
#include "dstring.h"
#include <string.h>

void main() {
    dstring ds1 = new_dstring("12a345aa6a78a9900a");
    dstring ds2 = new_dstring("ABcDE");

    printf("%d %s | %d %s \n", ds1.length, ds1.string, ds2.length, ds2.string);

    dstring* dsa = dstrsplit(&ds1, 'a');

    for ( ; dsa ; *dsa++) {
        printf("%s\t", dsa->string);
    }

    printf("%d %s | %d %s \n", ds1.length, ds1.string, ds2.length, ds2.string);
}