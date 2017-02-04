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

	FILE * ifp;
	FILE * ofp;

	ifp = fopen (a, "r");
	ofp = fopen (b, "w");
	
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
	
	FILE * ifp;
	FILE * ofp;

	ifp = fopen (a, "rb");
	ofp = fopen (b, "w");
	
	vector norm;
	vector *vector1 = &norm;
	float x, y, z;
	
	char line[1024];
	for (int i = 0; i < 10; i++) {
		fread(&norm, sizeof(norm), 1, ifp);
		vector_normalize(vector1);
		
		fprintf(ofp, "%f\t%f\t%f\t%f\t", norm.x, norm.y, norm.z ,norm.length);
	}
	fclose(ifp);
	fclose(ofp);
	return 0;
}

int readNormTextWriteNormBinary(char *a, char *b) {
	
	FILE * ifp;
	FILE * ofp;

	ifp = fopen (a, "r");
	ofp = fopen (b, "w");
	
	if (!ifp) {
		fprintf(stderr, "Unable to find requested file.\n");
		return 1;
	}
	
	vector vector1;
	vector vector2;
	int leng;
	float x, y, z, length;
	
	fseek(ifp, 0, SEEK_END);
	leng = ftell(ifp);
	char str[leng];
	char delim  = '\t';
	char *token;
	char *line = malloc(leng + 1);
	char c;
	
	for (int i; i < leng + 1; i++) {
		if (c = fgetc(ifp) != EOF) {
			*line++ = c;
		}
	}
	
	//while (fgets(line, sizeof(line), ifp)) {
		//sscanf(line, "%f\t%f\t%f\t%f\t%f\t%f\t", &x, &y, &z, &length);
		////vector1 = vector_init(x, y, z);
		
		
		//fprintf(stderr, "%f %f %f %f\n", x, y, z, length);
		//fwrite(&vector1, sizeof(vector1), 1, ofp);
	//}
	
	
	//char line[leng];
	
	//fread(str, leng + 1, 1, ifp);
	printf("%s\n", "hello");
	printf("%d\n", leng);
	printf("%s\n", str);
	printf("%s\n", line);
	
	//do 
    //{
      //*line++ = (char)fgetc(ifp);

    //} while(*line != EOF);
	
	
	//for (int i = 0; i < leng; i++) {
		//line[i] = (char)fgetc(ifp);
	//}
	printf("%s\n", line);
	fclose(ifp);
	//while (fgets(line, sizeof(line), ifp)) {
		//sscanf(line, "%s", &str);	
		//// fprintf(stderr, "%f %f %f %f\n", sum.x, sum.y, sum.z, sum.length);
	//}
	
	//token = strtok(str, s);
	//while (token != NULL) {
		
		//fwrite(&sum, sizeof(sum), 1, ofp);
		//token = strtok(str, s);
	//}	
	return 0;
}

int wc(char *a) {
	FILE * ifp;
	FILE * ofp;
	ifp = fopen (a, "r");
	if (!ifp) {
		fprintf(stderr, "Unable to find requested file.\n");
		return 1;
	}
	
	int numChars = 0;
	int numWords = 0;
	int numLines = 0;
	char c;
	
	while (c = fgetc(ifp) != EOF) {
		if (!isspace(c) && c != '\n') {
			numChars++;
		}
		if (isspace(c)) {
			numWords++;
		}
		if (c == '\n') {
			numLines++;
		}
	}
	
	fclose(ifp);
	printf("Number of characters: %d \n Number of words: %d \n Number of lines: %d\n", numChars, numWords, numLines);
	return 0;
}


