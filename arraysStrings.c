#include <string.h>
#include <stdlib.h>
#include "arraysStrings.h"
// reverse and append function 
char* joinrev(char *a, char *b) {
	
	int length;
	char temp, *c;
	length = 7;
	int lengtemp = length - 1;
	char world[8];
	memcpy(world, &b[0], 7);
	world[7] = '\0';

	for (int i = 0; i < length; i++) {
		temp = world[lengtemp];
		world[lengtemp] = world[i];
		world[i] = temp;
		lengtemp--;
		
		if (lengtemp == length / 2) {
			break;
		}
	}
	
	c = strcat(a, world);
	return c;
}

void *joinrev_generic(void *vects1, void *vects2, int typeSize, int numElementsA, int numElementsB) {
	
	// combine vectors 1 and 2 into vcr
	// (char*) vcr[numElementsA + numElementsB];
	char* charptr = (char*) vects1;
	char* charptr2 = (char*) vects2;
	char* vcr = malloc((numElementsA + numElementsB ) * typeSize);
	
	for (int i = 0; i < numElementsA * typeSize; i++) {
		vcr[i] = charptr[i];
	}
	
	for (int i = numElementsA * typeSize; i < (numElementsA + numElementsB) * typeSize; i++) {
		vcr[i] = charptr2[i - numElementsA * typeSize];
	}
	
	char *left=(char*) vcr + (numElementsA) * typeSize, *right=(char*)vcr+(numElementsA + numElementsB - 1)*typeSize;
	
	char temp[typeSize];
	while(left < right){
		memcpy(temp,right,typeSize);
		memmove(right,left,typeSize);
		memcpy(left,temp,typeSize);
		left+=typeSize;
		right-=typeSize;
	}
	
	return vcr;
}

int readTextAddBinary(char *a, char *b) {
	// take input file name (a), and output file name (b), and assign to filenames
	
	char fname[12];
	memcpy(fname, &a[0], 11);
	fname[11] = '\0';
	
	char output[12];
	memcpy(output, &b[0], 11);
	output[11] = '\0';
	FILE * ifp;
	FILE * ofp;

	ifp = fopen (fname, "r");
	ofp = fopen (output, "w");
	
	vector vector1;
	vector vector2;
	vector sum;
	
	float x1, y1, z1, x2, y2, z2;
	
	char line[1024];
	while (fgets(line, sizeof(line), ifp)) {
		sscanf(line, "%f %f %f %f %f %f\n", &x1, &y1, &z1, &x2, &y2, &z2);
		vector1 = vector_init(x1, y1, z1);
		vector2 = vector_init(x2, y2, z2);
		sum = vector_add(vector1, vector2);
		
		// fprintf(stderr, "%f %f %f %f\n", sum.x, sum.y, sum.z, sum.length);
		fwrite(&sum, sizeof(sum), 1, ofp);
	}
	fclose(ofp);
	return 0;
}

int readBinaryNormText(char *a, char *b) {
	char fname[12];
	memcpy(fname, &a[0], 11);
	fname[11] = '\0';
	
	char output[9];
	memcpy(output, &b[0], 8);
	output[8] = '\0';
	
	FILE * ifp;
	FILE * ofp;

	ifp = fopen (fname, "r");
	ofp = fopen (output, "w");
	
	vector* vector1 = malloc(sizeof(vector));
	vector norm;
	
	float x, y, z, length;
	
	char line[1024];
	while (fgets(line, sizeof(line), ifp)) {
		sscanf(line, "%f %f %f\n", &x, &y, &z);
		//fprintf(stderr, "%f %f %f\n", x, y, z);
		*vector1 = vector_init(x, y, z);
		if (!vector_normalize(vector1)) {
			fprintf(ofp, "%f\t%f\t%f\t%f\t", (*vector1).x, (*vector1).y, (*vector1).z, (*vector1).length);
		}
		//norm = vector_init(x, y, z);
		//vector_normalize((vector*)norm);
		
		//fprintf(stderr, "%f %f %f %f\n", (*vector1).x, (*vector1).y, (*vector1).z, (*vector1).length);
		//fwrite(&vector1, sizeof(vector1), 1, ofp);
		
		//fprintf(ofp, "%f\t%f\t%f\t%f\t", norm.x, norm.y, norm.z, norm.length);
		//vector1 = malloc(sizeof(vector));
	}
	fclose(ifp);
	fclose(ofp);
	return 0;
}

int readNormTextWriteNormBinary(char *a, char *b) {
	// string tok
}

int wc(char *a) {
	
}


