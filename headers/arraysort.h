//Header file (*.h)
//Array of Intergers Sorting functions 
//Written by Minh N. Nguyen (s3877222)
//Licensed under GNU General Public License v3.0, visit https://www.gnu.org/licenses/gpl-3.0.en.html for more info

#include <stdio.h>

//Functions declarations
/*
    Technically, functions should take these arguments, repectively:
	int sortsize: the number of elements to be sorted, starting from array pointer.
	int* array: the pointer to the initial elements of a sequence of an array.
	int order: the integer indicates the order of the sort ("+" value for ascending and "-" value for descending).
		   An inappropriate integer choice may cause unwanted function behaviour, keep that in mind.
*/

//Bubble sort function
void bubblesort (int sortsize, int* array, int order);

//Functions definitions
//Damn, none of 'em are pure
//#saveHaskell

//Bubble sort function 
void bubblesort (int sortsize, int *array, int order) {
    for (int i=0; i<sortsize; i++) {
	for (int j=i+1; j<sortsize; j++) {
	    if ((*(array + j)*order) < (*(array + i)*order)) {
		int swp = *(array + i);
		*(array + i) = *(array + j);
		*(array + j) = swp;
	    }
	}
    }
}

//End of Header file
//I'm so sorry if there's any typos, my bad
//God danm stiky keys
//Sincerely,
//Minh N. Nguyen Mr. :)))
