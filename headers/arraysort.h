//Header file (*.h)
//Array of Intergers Sorting functions 
//Written by Minh N. Nguyen (s3877222)
//Licensed under GNU GPL v3.0, visit https://www.gnu.org/licenses/gpl-3.0.en.html for more info

#include <stdio.h>

//Functions declarations
//Bubble sort function
void bubblesort (int arraysize, int* array);

//Fucntions definitions
//Damn none of 'em are pure
//#saveHaskell

//Bubble sort function 
void bubblesort (int arraysize, int *array) {
    for (int i=0; i<arraysize; i++) {
	for (int j=i+1; j<arraysize; j++) {
	    //if latter arrar element is greater than the former then swap pos
	    if (array[j] < array[i]) {
		int swp = array[j];
		array[j] = array[i];
		array[i] = swp;
	    }
	   
	}
    }
}

//End of Header file
