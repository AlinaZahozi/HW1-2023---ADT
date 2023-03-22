# ADT- Adaptive Array Implementation

This repository contains an implementation of an adaptive array in C. The adaptive array is a dynamic data structure that can grow as elements are added. This implementation provides functions for creating, deleting, and modifying the array, as well as functions for getting and printing elements in the array.



**Installation:**

To use this implementation, simply clone the repository to your local machine:

	git clone https://github.com/AlinaZahozi/HW1-2023---ADT.git
	

**Usage:**

![Screenshot from 2023-03-22 22-00-29](https://user-images.githubusercontent.com/93255163/227024058-87afe782-939b-4525-849d-95056cc0dd26.png)


**Creating an Adaptive Array:**

To create an adaptive array, call the CreateAdptArray function, passing in functions to handle copying, deleting, and printing elements of the array. 


**Setting and Getting Elements:**

To set an element at a specific index in the array, call the SetAdptArrayAt function, passing in the array, the index, and the element to be set. If the index is outside the current bounds of the array, the array will be resized to accommodate the new element.To get an element at a specific index in the array, call the GetAdptArrayAt function, passing in the array and the index. If the index is out of bounds, the function will return NULL.


**Getting the Size:**

To get the size of the array, call the GetAdptArraySize function, passing in the array. If the array is NULL, the function will return -1.


**Printing the Array:**

To print the contents of the array, call the PrintDB function, passing in the array. This function will print each non-NULL element of the array using the print function specified when creating the array.


**Deleting the Array:**

To delete an adaptive array and free all of its memory, call the DeleteAdptArray function, passing in the array. This function will also call the delete function specified when creating the array on each non-NULL element in the array.
