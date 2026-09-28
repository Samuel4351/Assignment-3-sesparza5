//Samuel Esparza
//Due September 28, 2026

//FILE FUNCTION - This contains the functions and how they operate



#include <stdio.h>
#include <stdlib.h>
#include "array.h"



//OUTPUT ARRAY FUNCTION
void output_array(Array *a)
{
	for(int row = 0; row < a->size; row++)
	{
		printf("%.2f ", a->data[row]);
	}

	printf("\n");
}



//SHIFT ARRAY FUNCTION
void shift_array(Array *a)
{
	//save the first value
	double first = a->data[0];

	//now to shift evrry value to the left 
	for(int row = 0; row < a->size - 1; row++)
	{
		a->data[row] = a->data[row + 1];
	}

	//now to put orginal first value at the end
	a->data[a->size -1] = first;
}



//AVERAGE ADJACENT ARRAY FUNCTION 
//- creates new array a containing the averages of adjacent elements
Array *average_adjacent(Array *a)
{
	//Allocating memory for a new array structure
	Array *new_array = malloc(sizeof(Array));

	//Check if malloc worked
	if (new_array == NULL)
	{
		printf("Memory allocation failed.\n");
		return NULL;
	}


	//New array must be half the size of original
	new_array->size = a->size / 2;

	//Allocate memory for new arrays data
	new_array->data = malloc(new_array->size * sizeof(double));

	//Check if malloc worked
	if (new_array->data == NULL)
	{
		printf("Memory allocation failed.\n");

		free(new_array);

		return NULL;
	}


//Now to average each pair of numbers
	for(int row = 0; row < new_array->size; row++)
	{
		new_array->data[row] = (a->data[row *2] + a-> data[row *2 +1]) / 2;
	}


//Finally returning the new array
	return new_array;
}



