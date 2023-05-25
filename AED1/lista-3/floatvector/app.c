#include "floatVector.h"
#include <stdio.h>
#include <stdlib.h>



int main() {

    FloatVector *vec = create(10);

    puts("Hello!");

    destroy(&vec);

    return 0;
}