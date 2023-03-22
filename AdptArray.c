#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "AdptArray.h"

typedef struct AdptArray_{
int size;
PElement* arr;
DEL_FUNC delete_element;
COPY_FUNC copy_element;
PRINT_FUNC print_element;
} *PAdptArray;

PAdptArray CreateAdptArray(COPY_FUNC c, DEL_FUNC d ,PRINT_FUNC p){
    PAdptArray array = (PAdptArray)malloc(sizeof(struct AdptArray_));
	if(!array) return NULL;
	array->size = 0;
    array->arr = NULL;
    array->delete_element = d;
    array->copy_element = c;
    array->print_element = p;
	return array;
}

void DeleteAdptArray(PAdptArray array){
    int arr_size = GetAdptArraySize(array);
    if(arr_size == 0){
        free(array);
    }
    else if (arr_size != -1) {
        for(int i = 0 ; i < arr_size ; i++){
            if((array->arr)[i]){
                array->delete_element((array->arr)[i]);
            }
        }
        free(array->arr);
        free(array);
    }
}

Result SetAdptArrayAt(PAdptArray array, int index, PElement m){
    if(!array) return FAIL;
    int arr_size = GetAdptArraySize(array);
    if((0 <= index) && (index < arr_size)){
        if((array->arr)[index] != NULL){
            array->delete_element((array->arr)[index]);
        }
        //(array->arr)[index] = array->copy_element(m);
        //return SUCCESS;
        PElement type = array->copy_element(m);
        if(type != NULL){
            (array->arr)[index] = type;
            return SUCCESS;
        }
    }
    else if (index >= arr_size){

        PElement* new_arr = (PElement*)calloc((index+1),sizeof(PElement));
        if(!new_arr) return FAIL;
        memcpy(new_arr, array->arr, (arr_size)*sizeof(PElement));
        free(array->arr);
        array->arr = new_arr;

        PElement type = array->copy_element(m);
        if(type != NULL){
            (array->arr)[index] = type;
            return SUCCESS;
        }
    }
    return FAIL;
}

PElement GetAdptArrayAt(PAdptArray array, int index){
    int arr_size = GetAdptArraySize(array);
    if(!array || arr_size == 0) return NULL;
    if((0 <= index) && (index < arr_size)){
       PElement type = array->copy_element(array->arr[index]);
       if(!type) return NULL;
       return type;
    }
    return NULL;
}

int GetAdptArraySize(PAdptArray array){
    if(array->arr != NULL) return array->size;
    return -1;
}

void PrintDB(PAdptArray array){
    int arr_size = GetAdptArraySize(array);
    if(arr_size != 0){
       for(int i = 0 ; i < arr_size ; i++){
        array->print_element((array->arr)[i]);
        } 
    }
}