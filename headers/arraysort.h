//Integer Array sorting functions Header file.
//Written by Minh N. Nguyen 
//Licensed under GNU General Public License v3.0, visit https://www.gnu.org/licenses/gpl-3.0.en.html for more info

//HEADER FILE USAGE
/*     
    Put this header file in a subdirectory where your code you want to include the header is located. (Preferably header/ directory)
    Add the line below to the #include path of your C code
	#include "header/arraysort.h" 
    The name path to the directory of the header file might vary according to where your header is, for example:
	"arraysort.h" if you put the head file in the same directory of your code.
	"<your-directory-name>/arraysort.h" if you put the header file in your custom-named directory.
*/

#include <stdio.h>

//FUNCTION DECLARATIONS
/*
    Each function should follow this convention of function arguments, respectively:
	int sortsize: the length of the array sequence to be sorted.
	int* array: the pointer to the initial element of the sequence.
	int order:  the integer argument represents the sorting order (ascending/descending).
		    Positive number represents ascending order, and vice versa.
		    [WARNING]:	Inappropiate argument might cause unwanted function behaviour. Keep that in mind.
*/

void bubblesort (int sortsize, int* array, int order);
void selectionsort (int sortsize, int* array, int order);
void insertionsort (int sortsize, int* array, int order);

//FUNCTION DEFINITIONS
void bubblesort (int sortsize, int* array, int order) {
    int sorder = 0;
    if (order > 0)  sorder = 1; else sorder = -1;   
    for (int i=0; i<sortsize; i++) {
	for (int j=i+1; j<sortsize; j++) {
	    //If former array element is greater than the latter, swap their position
	    if ((array[j]*sorder) < (array[i]*sorder)) {
		array[i] += array[j];
		array[j] = array[i] - array[j];
		array[i] -= array[j];
	    }
	}
    }
}


void selectionsort (int sortsize, int* array, int order) {
    int sorder = 0;
    if (order > 0)  sorder = 1; else sorder = -1;    
    for (int i=0; i<sortsize; i++) {
	int slcelem = i;
	for (int j=i+1; j<sortsize; j++) {
	    if (
		    (array[j]*sorder < array[i]*sorder)		    //If the former array element is greater than the latter 
		    && (array[j]*sorder < array[slcelem]*sorder)    //And the latter one is less than the current selected element
	    ) slcelem = j;  //Select current j-th element		
	}
	if (slcelem != i) {
	    array[i] += array[slcelem];
	    array[slcelem] = array[i] - array[slcelem];
	    array[i] -= array[slcelem];
	}
    }
}


void insertionsort (int sortsize, int* array, int order) {
    int sorder = 0;
    if (order > 0)  sorder = 1; else sorder = -1;    
    for (int i=1; i<sortsize; i++) {
	int inspos = i;	    //Insert position
	while (
	    (*(array + inspos - 1)*sorder > array[i]*sorder)    //Finding the largest element less than and prior to the current element
	    && (inspos>0)   //Segfault prevention
	) inspos--; 
	if (inspos != i) {  //If current element is not in sorted order, perform insertion
	    for (int j=inspos; j<i; j++) {  //Insert and Shift elements to the right	 
		array[i] += array[j];
		array[j] = array[i] - array[j];
		array[i] -= array[j];
	    }
	}
    }
}

//End of Header file
