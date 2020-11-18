//Header file (*.h)
//Array of Intergers Sorting functions 
//Written by Minh N. Nguyen 
//Licensed under GNU General Public License v3.0, visit https://www.gnu.org/licenses/gpl-3.0.en.html for more info

#include <stdio.h>

//Functions declarations
/*
    Technically, functions should take these arguments, repectively:
	int sortsize: the number of elements to be sorted, starting from array pointer.
	int* array: the pointer to the initial elements of a sequence of an array.
	int order: the integer indicates the order of the sort (positive value for ascending and negative value for descending).
		   An inappropriate integer choice may cause unwanted function behaviour, keep that in mind.
*/

//Bubble sort function
void bubblesort (int sortsize, int* array, int order);
//Selection sort function
void selection (int sortsize, int* array, int order);

//Functions definitions
//Damn, none of 'em are pure
//#saveHaskell

//Bubble sort function 
void bubblesort (int sortsize, int* array, int order) {
    int sorder = 0;
    if (order > 0)  sorder = 1; else sorder = -1;    //To avoid memory overflows, array element multiplier should be either 1 or -1
    for (int i=0; i<sortsize; i++) {
	for (int j=i+1; j<sortsize; j++) {
	    //If former array element is greater than the latter, swap their position
	    if ((*(array + j)*sorder) < (*(array + i)*sorder)) {
		*(array + i) += *(array + j);
		*(array + j) = *(array + i) - *(array + j);
		*(array + i) -= *(array + j);
	    }
	}
    }
}

//Selection sort function
void selectionsort (int sortsize, int* array, int order) {
    int sorder = 0;
    if (order > 0)  sorder = 1; else sorder = -1;    //To avoid memory overflows, array element multiplier should be either 1 or -1
    for (int i=0; i<sortsize; i++) {
	int slcelem = i;
	for (int j=i+1; j<sortsize; j++) {
	    if (
		    (*(array + j)*sorder < *(array + i)*sorder) //If the former array element is greater than the latter 
		    && (*(array + j)*sorder < *(array + slcelem)*sorder)   //And the latter one is less than the current selected element
	    ) slcelem = j; //Select current j-th element		
	}
	if (slcelem != i) {
	    *(array + i) += *(array + slcelem);
	    *(array + slcelem) = *(array + i) - *(array + slcelem);
	    *(array + i) -= *(array + slcelem);
	}
    }
}

//End of Header file
