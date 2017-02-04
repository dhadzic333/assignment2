//other includes are necessary
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "vectors.h"
//fill in the parameters and return type
char* joinrev(char *a, char *b);
void *joinrev_generic(void *vects1, void *vects2, int typeSize, int numElementsA, int numElementsB);
int readTextAddBinary(char *a, char *b);
int readBinaryNormText(char *a, char *b);
int readNormTextWriteNormBinary(char *a, char *b);
int wc(char *a);
