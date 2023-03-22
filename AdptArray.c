#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "AdptArray.h"


// Define a struct to represent the adaptive array
typedef struct AdptArray_{
    int size;
    PElement* arr;
    DEL_FUNC delete_element;
    COPY_FUNC copy_element;
    PRINT_FUNC print_element;
} AdptArray;

// Create a new adaptive array with the given copy, delete and print functions
PAdptArray CreateAdptArray(COPY_FUNC c, DEL_FUNC d ,PRINT_FUNC p){
    // Allocate memory for the array
    PAdptArray array = (PAdptArray)malloc(sizeof(AdptArray));
    if(!array) return NULL;
    // Set initial values
    array->size = 0;
    array->arr = NULL;
    array->delete_element = d;
    array->copy_element = c;
    array->print_element = p;
    return array;
}

// Delete an adaptive array and free all of its memory
void DeleteAdptArray(PAdptArray array){
    if(!array) return;
    int arr_size = GetAdptArraySize(array);
    if(arr_size == 0){
    	// If the array is empty, just free it
        free(array);
    }
    else if (arr_size != -1 && arr_size != 0) {
    	// Otherwise, loop through the array and delete each element
        for(int i = 0 ; i < arr_size ; i++){
            if((array->arr)[i] != NULL){
                array->delete_element((array->arr)[i]);
            }
        }
        // Free the array and then the adaptive array itself
        free(array->arr);
        free(array);
    }
}

// Set the value at the given index to the given element
Result SetAdptArrayAt(PAdptArray array, int index, PElement m){
    if(!array) return FAIL; // Check if array pointer is null and return FAIL if so
    int arr_size = GetAdptArraySize(array); // Get current size of the array
    if((0 <= index) && (index < arr_size)){ // Check if index is within current bounds of the array
     	// If the index is within the current bounds of the array, just set the value
        // If there was an existing element at that index, delete it first
        if((array->arr)[index] != NULL){
            array->delete_element((array->arr)[index]);
        }
        (array->arr)[index] = array->copy_element(m);// Copy the new element into the array
        if((array->arr)[index] != NULL){
            return SUCCESS; // If the insertion was successful, return SUCCESS
        }
    }
    else if (index >= arr_size){
	// If the index is outside the current bounds of the array, resize the array
        // Allocate memory for a new array with a larger size, and copy the old elements to it
	PElement* new_arr;
        new_arr = (PElement*) calloc((index+1),sizeof(PElement));
        if(new_arr == NULL) return FAIL; // If memory allocation failed, return FAIL
        memcpy(new_arr, array->arr, (array->size) * sizeof(PElement)); // Copy old elements to the new array
        free(array->arr); // Free the old array
        array->arr = new_arr; // Point to the new array
        array->size = index+1; // Update the size of the array

        (array->arr)[index] = array->copy_element(m); // Copy the new element into the array
        if((array->arr)[index] != NULL){
            return SUCCESS; // If the insertion was successful, return SUCCESS
        }
    }
    return FAIL; // Return FAIL if the insertion was unsuccessful
}

PElement GetAdptArrayAt(PAdptArray array, int index){
    // Get the size of the array
    int arr_size = GetAdptArraySize(array);
    // Return NULL if the array is NULL or has size 0
    if(!array || arr_size == 0) return NULL;
    // If the index is within the current bounds of the array, get the element
    if((0 <= index) && (index < arr_size)){
    	// If the element at the given index is not NULL, copy and return it
    	if(array->arr[index] != NULL){
    		return array->copy_element((array->arr)[index]);
    	}
    } 
    return NULL; // If the index is out of bounds, return NULL
}

int GetAdptArraySize(PAdptArray array){
    // If the array is not NULL, return its size
    if(array->arr != NULL) return array->size;
    // Otherwise, return -1 to indicate an error
    return -1;
}

void PrintDB(PAdptArray array){
    // Get the size of the array
    int arr_size = GetAdptArraySize(array);
    // If the array is not empty, loop through its elements and print them
    if(arr_size != 0){
       for(int i = 0 ; i < arr_size ; i++){
       	// If the element at the current index is not NULL, print it
       	if(array->arr[i] != NULL){
        	array->print_element((array->arr)[i]);
        } 
       }
    }
}
