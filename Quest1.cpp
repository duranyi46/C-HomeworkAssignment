#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

enum { SUCCESS, FAIL };

int main() {
    int studentNumber[8] = {9, 0, 2, 3, 0, 7, 6, 7}; /* Creating array, its size and files even.txt and odd.txt */
    int size = sizeof(studentNumber) / sizeof(studentNumber[0]);
    FILE *fptr1, *fptr2, *fptr3;
    char filename1[] = "even.txt";
    char filename2[] = "odd.txt";
    int reval = SUCCESS;

    if ((fptr1 = fopen(filename1, "w")) == NULL) { /* In case even.txt cannot be opened */
        printf("Can't open %s\n", filename1);
        return FAIL;
    } else if ((fptr2 = fopen(filename2, "w")) == NULL) { /* In case odd.txt cannot be opened */
        printf("Can't open %s\n", filename2);
        fclose(fptr1);
        return FAIL;
    } else { /* Both text files are created and opened. Writing even and odd integers corresponding files */
        for (int i = 0; i < size; i++) {
            if (studentNumber[i] % 2 == 0) {
                fprintf(fptr1, "%i ", studentNumber[i]);
            } else {
                fprintf(fptr2, "%i ", studentNumber[i]);
            }
        }
    }
    fclose(fptr1);
    fclose(fptr2); /* End of part a */

    if ((fptr1 = fopen(filename1, "r+")) == NULL) { /* In case even.txt cannot be opened */
        printf("Can't open %s\n", filename1);
        return FAIL;
    } else if ((fptr2 = fopen(filename2, "r+")) == NULL) { /* In case odd.txt cannot be opened */
        printf("Can't open %s\n", filename2);
        fclose(fptr1);
        return FAIL;
    } else { /* Both text files are created and opened. Reading integers and calculating sums */
        int integer, even_sum = 0, odd_sum = 0; /* Defining variables for calculating sums */
        while (fscanf(fptr1, "%i", &integer) == 1) { /* Calculating even integers sum */
            even_sum += integer;
        }
        while (fscanf(fptr2, "%i", &integer) == 1) { /* Calculating odd integers sum */
            odd_sum += integer;
        }
        fprintf(fptr1, " %i", even_sum); /* Appending sum of even and odd integers at the end of the first lines of each file */
        fprintf(fptr2, " %i", odd_sum);
    }
    fclose(fptr1);
    fclose(fptr2); /* End of part b */

    fptr3 = fopen("text.txt", "r");
    if (fptr3 == NULL) { /* In case text.txt cannot be opened */
        printf("Can't open text.txt\n");
        return FAIL;
    } else { /* text.txt opened */
        int letter, count = 0;
        int *ascii_values = NULL;
        while ((letter = getc(fptr3)) != EOF) { /* reading text */
            if (isalpha(letter)) { /* checking whether it is a letter or not */
                ascii_values = (int *)realloc(ascii_values, (count + 1) * sizeof(int)); /* dynamically allocating memory for valid ascii values while reading */
                if (ascii_values == NULL) {
                    printf("Memory can not be allocated.\n");
                    return FAIL;
                }
                ascii_values[count++] = letter; /* if it is a letter get its ascii value in array */
            }
        }
        fclose(fptr3); /* closing text.txt */

        if ((fptr1 = fopen(filename1, "a")) == NULL) { /* In case even.txt cannot be opened */
            printf("Can't open %s\n", filename1);
            free(ascii_values);
            return FAIL;
        } else if ((fptr2 = fopen(filename2, "a")) == NULL) { /* In case odd.txt cannot be opened */
            printf("Can't open %s\n", filename2);
            free(ascii_values);
            return FAIL;
        } else { /* Both text files are created and opened. Writing even and odd ascii values corresponding files */
            fprintf(fptr1, "\n"); /* for new line */
            fprintf(fptr2, "\n"); /* for new line */
            for (int i = 0; i < count; i++) {
                if (ascii_values[i] % 2 == 0) {
                    fprintf(fptr1, "%i ", ascii_values[i]);
                } else {
                    fprintf(fptr2, "%i ", ascii_values[i]);
                }
            }
            fclose(fptr1);
            fclose(fptr2);
        }
        free(ascii_values);
    } /* END OF THE QUEST 1 */

	fptr3 = fopen("text.txt", "r");
    if (fptr3 == NULL) { /* In case text.txt cannot be opened */
        printf("Can't open text.txt\n");
        return FAIL;
    } else {	/* text.txt opened */
		int letter;
		int aCount = 0; 
		int eCount = 0; 
		int oCount = 0; 
		int iCount = 0; 
		int uCount = 0; /*  defining vowel counts */
		while ((letter = getc(fptr3)) != EOF) { /* reading text */
    		letter = tolower(letter); /* for switch-case all letters must be case sensitive */
			switch(letter){ /* switch-case four counting vowels */
				case 'a':
					++aCount;
					break;
				case 'e':
					++eCount;
					break;
				case 'o':
					++oCount;
					break;
				case 'i':
					++iCount;
					break;
				case 'u':
					++uCount;
					break;
			}
		}
	fclose(fptr3); /* closing text.txt */
	printf("Number of a : %d\n",aCount); /* displaying each vowel count */
	printf("Number of e : %d\n",eCount);
	printf("Number of o : %d\n",oCount);
	printf("Number of i : %d\n",iCount);
	printf("Number of u : %d\n",uCount);
	} /* End of Quest2 Part a */
	
	
    return reval;
	}

