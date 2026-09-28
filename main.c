//Samuel Esparza
//Due September 28, 2026

//Description - custom structure that stores an array along 
//with the size in a single data type.  The size of the array 
//will be chosen by the user using command line arguments. 
//We will then pass this array to various functions that 
//operate on the data inside.

//FILE FUCNTION - Where we will run all fucntions and files

//INSTRUCTIONS ON HOW TO RUN PROGRAM
//use ths to compile - gcc -o main main.c array.c
//hen run with ex this - ./main 6




//Include our normal libraries and ones i created 
#include <stdio.h>
#include <stdlib.h>
#include "array.h"



int main(int argc, char *argv[])
{
	//to check if user entered an array size
	if (argc != 2)
	{
		printf("Usage: ./main <array size>\n");
		return 1;
	}


	//Converting command line argument from text to a integer
	int size = atoi(argv[1]);

	//Makeing sure that the size is valid
	if (size <= 0)
	{
		printf("Array size must be a Posotive (+) Number\n");
		return 1;
	}


//ALLOCATE MEMORY FOR ONE ARRAY STRUCTURE
	Array *a = malloc(sizeof(Array));

	//check if malloc worked
	if(a == NULL)
	{
		printf("Memory allocation failed\n");
		return 1;
	}


	//Store the size inside structure
	a->size = size;

	//Allocate memory for the data array
	a->data = malloc(size * sizeof(double));

	//Check if malloc worked again
	if(a->data == NULL)
	{
		printf("Memory allocation failed\n");
		free(a);
		return 1;
	}


	//Now to fill the array with values
//HERE IF YOU WOULD LIKE YOU CAN CHANGE AND ADD CODE TO MAKE A DIFFERENT 
//NUMBERED ARRAY RATHER THEN JUST 1, 2, 3, 4, ...
	for (int row = 0; row < a->size; row++)
	{
		a->data[row] = row + 1;
	}

//PRINTING ORIGINAL ARRAY
	printf("Original Array: \n");
	output_array(a);

//SHIFT THE ARRAY
	shift_array(a);

//PRINT SHIFTED ARRAY
	printf("Shifted Array:\n");
	output_array(a);

//CREATE ARRAY CONTAINING ADJACENT AVERAGES
	Array *average_array = average_adjacent(a);

	//check to see it workes
	if(average_array == NULL)
	{
		printf("Memory allocation failed.\n");

		free(a->data);
		free(a);

	return 1;
	}

//PRINT AVERAGED ARRAY
	printf("Average Adjacent Array: \n");
	output_array(average_array);

//FREE AVERAGE ARRAY and ORIGINAL ARRAY
	free(average_array->data);
	free(average_array);

	free(a->data);
	free(a);




	return 0;


}




