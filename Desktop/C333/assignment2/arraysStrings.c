#include "arraysStrings.h"
#include <string.h>
#include <stdlib.h>

// reverse and append function 
char joinrev(char a, char b) {
	
	int length;
	char temp, c;
	length = strlen(b) - 1;
	int lengtemp = length;
	char original[length]; strcpy (original, b);
	char reverse[length]; strcpy (reverse, b);
	for (int i = 0; i < length; i++) {
		// temp = original[lengtemp];
		reverse[lengtemp] = original[i];
		// reverse[i] = temp;
		lengtemp--;
		
		if (lengtemp == length / 2) {
			break;
		}
	}
	
	c = strcat(a, reverse);
	return c;
}

int readTextAddBinary(char a, char b) {
	
}


