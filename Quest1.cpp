#include <stdio.h>

enum {SUCCESS,FAIL};

int main()
{
	int studentNumber[8] = {9,0,2,3,0,7,6,7}; /* Creating array, its size and files even.txt and odd.txt */
	int size = sizeof(studentNumber) / 4;
	FILE *fptr1, *fptr2;
	char filename1[]= "even.txt";
	char filename2[]= "odd.txt";
	int reval = SUCCESS;
	
	if ((fptr1 = fopen(filename1, "w")) == NULL) { /* In case even.txt cannot be opened */
	printf("Can't open %s\n",filename1);
	reval = FAIL;
	} else if ((fptr2 = fopen(filename2, "w")) == NULL) { /* In case odd.txt cannot be opened */
	printf("Can't open %s\n",filename2);
	reval = FAIL;
	} else { /* Both text files are created and opened. Writing even and odd integers corresponding files */
	for (int i = 0; i < size; i++) {
		if (studentNumber[i] % 2 == 0) {
			fprintf(fptr1, "%i ",studentNumber[i]);
		} else {
			fprintf(fptr2, "%i ",studentNumber[i]);
		}
	}
	 }
	fclose(fptr1); fclose(fptr2); /* End of part a */
	
	if ((fptr1 = fopen(filename1, "r+")) == NULL) { /* In case even.txt cannot be opened */
	printf("Can't open %s\n",filename1);
	reval = FAIL;
	} else if ((fptr2 = fopen(filename2, "r+")) == NULL) { /* In case odd.txt cannot be opened */
	printf("Can't open %s\n",filename2);
	reval = FAIL;
	} else { /* Both text files are created and opened. Reading integers and calculating sums */
	int integer, even_sum = 0, odd_sum = 0; /* Defining variables for calculating sums */
	while (fscanf(fptr1, "%i", &integer) == 1) { /* Calculating even integers sum */
		even_sum += integer;
	}
	while (fscanf(fptr2, "%i", &integer) == 1) { /* Calculating odd integers sum */
		odd_sum += integer;
	}
	fprintf(fptr1, "%i",even_sum); /* Appending sum of even and odd integers at the end of the first lines of each file */
	fprintf(fptr2, "%i",odd_sum);
	 }
	fclose(fptr1); fclose(fptr2); /* End of part b */
	
	return reval;
	}
	
	
	
