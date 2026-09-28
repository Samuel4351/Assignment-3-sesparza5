//Samuel Esparza
//Due September 28, 2026

//FILE FUNCTION - Where our custum array structor exist
//Define function Declarations - this tells the computer that these
//                               functions exist and how to call them


#ifndef ARRAY_H
#define ARRAY_H


//CUSTUM ARRAY STRUCTURE
struct _my_array

{
	int size;
	double *data;
};

typedef struct _my_array Array;


//FUNCTION DECLARATIONS
void output_array(Array *a);

void shift_array(Array *a);

Array *average_adjacent(Array *a);



#endif
