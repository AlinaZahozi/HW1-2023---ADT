#include <stdlib.h>
#include <stdio.h>
#include "AdptArray.h"

typedef struct AdptArray_{
int size;
PElement* arr;
DEL_FUNC delete_element;
COPY_FUNC copy_element;
PRINT_FUNC print_element;
} *PAdptArray;

PAdptArray CreateAdptArray(COPY_FUNC, DEL_FUNC,PRINT_FUNC){
    PAdptArray array = (PAdptArray)malloc(sizeof(struct AdptArray_));
	if(!array) return NULL;
	array->size = 0;
    array->arr = NULL;
    array->delete_element = &DEL_FUNC;
    array->copy_element = &COPY_FUNC;
    array->print_element = &PRINT_FUNC;
	return array;
}

void DeleteAdptArray(PAdptArray array){
    int arr_size = GetAdptArraySize(array);
    if(arr_size == 0){
        free(array);
    }
    else if (arr_size != -1) {
        for(int i = 0 ; i < array.size ; i++){
            array.arr[i].delete_element;
        }
        free(array)
    }

}

Result SetAdptArrayAt(PAdptArray array, int index, PElement m){
    int arr_size = GetAdptArraySize(array);
    if((-1 < index) && (index < arr_size)){
       
    }
    else if (index > arr_size){

    }
    return FAIL;
}

PElement GetAdptArrayAt(PAdptArray array, int index){
    int arr_size = GetAdptArraySize(array);
    if((-1 < index) && (index < arr_size)){
       
    }
    else if (index > arr_size){

    }
    return NULL;
}

int GetAdptArraySize(PAdptArray array){
    if(array.arr != NULL) return array.size;
    return -1;
}

void PrintDB(PAdptArray array){
    int arr_size = GetAdptArraySize(array);
    for(int i = 0 ; i < arr_size ; i++){
        
    }
}