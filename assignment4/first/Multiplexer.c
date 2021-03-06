#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Multiplexer.h"

#define TOINDEX(x) (x > 90? x - 71 : x - 65)
#define GETVALUE(y) (y > 49? values[TOINDEX(y)] : y - 48 )

void Multiplexer_Multiplex2to1(FILE* circuitDescription, int* values)
	{
		char inputs[2],
		     selector,
				 output; 
		int index;


		for (index = 0; index < 2; index++)
				fscanf(circuitDescription, "%c%*[ \t\n\v\f\r]", &inputs[index]);

		fscanf(circuitDescription, "%c%*[ \t\n\v\f\r]", &selector);
		fscanf(circuitDescription, "%c%*[ \t\n\v\f\r]", &output);


		int input1 = GETVALUE(inputs[0]),
				input2 = GETVALUE(inputs[0]),

		    selector1 = GETVALUE(selector);


		values[TOINDEX(output)] = (!selector1) ? input1 : input2; 
	}


void Multiplexer_Multiplex4to1(FILE* circuitDescription, int* values)
	{
		char inputs[4],
		     selectors[2],
				 output; 
		int index; 


		for (index = 0; index < 4; index++)
				fscanf(circuitDescription, "%c%*[ \t\n\v\f\r]", &inputs[index]);

		for (index = 0; index < 2; index++)
				fscanf(circuitDescription, "%c%*[ \t\n\v\f\r]", &selectors[index]);

		fscanf(circuitDescription, "%c%*[ \t\n\v\f\r]", &output);


		int input1 = GETVALUE(inputs[0]),
				input2 = GETVALUE(inputs[1]),
				input3 = GETVALUE(inputs[2]),
				input4 = GETVALUE(inputs[3]),

		    selector1 = GETVALUE(selectors[0]),
		    selector2 = GETVALUE(selectors[1]);


		if (!selector1 && !selector2)
				values[TOINDEX(output)] = input1;

		else if (!selector1 && selector2)
				values[TOINDEX(output)] = input2;

		else if (selector1 && selector2)
				values[TOINDEX(output)] = input3;

		else 
				values[TOINDEX(output)] = input4;
	}


void Multiplexer_Multiplex8to1(FILE* circuitDescription, int* values)
	{
		char inputs[8],
		     selectors[3],
				 output; 
		int index;


		for (index = 0; index < 8; index++)
				fscanf(circuitDescription, "%c%*[ \t\n\v\f\r]", &inputs[index]);

		for (index = 0; index < 3; index++)
				fscanf(circuitDescription, "%c%*[ \t\n\v\f\r]", &selectors[index]);

		fscanf(circuitDescription, "%c%*[ \t\n\v\f\r]", &output);


		int input1 = GETVALUE(inputs[0]),
				input2 = GETVALUE(inputs[1]),
				input3 = GETVALUE(inputs[2]),
				input4 = GETVALUE(inputs[3]),
				input5 = GETVALUE(inputs[4]),
				input6 = GETVALUE(inputs[5]),
				input7 = GETVALUE(inputs[6]),
				input8 = GETVALUE(inputs[7]),

		    selector1 = GETVALUE(selectors[0]),
		    selector2 = GETVALUE(selectors[1]),
		    selector3 = GETVALUE(selectors[2]);


		if (!selector1 && !selector2 && !selector3)
				values[TOINDEX(output)] = input1;

		else if (!selector1 && !selector2 && selector3)
				values[TOINDEX(output)] = input2;

		else if (!selector1 && selector2 && selector3)
				values[TOINDEX(output)] = input3;

		else if (!selector1 && selector2 && !selector3)
				values[TOINDEX(output)] = input4;

		else if (selector1 && selector2 && !selector3)
				values[TOINDEX(output)] = input5;

		else if (selector1 && selector2 && selector3)
				values[TOINDEX(output)] = input6;

		else if (selector1 && !selector2 && selector3)
				values[TOINDEX(output)] = input7;

		else
				values[TOINDEX(output)] = input8;
	}


void Multiplexer_Multiplex16to1(FILE* circuitDescription, int* values)
	{
		char inputs[16],
		     selectors[4],
				 output; 
		int index;


		for (index = 0; index < 16; index++)
				fscanf(circuitDescription, "%c%*[ \t\n\v\f\r]", &inputs[index]);

		for (index = 0; index < 4; index++)
				fscanf(circuitDescription, "%c%*[ \t\n\v\f\r]", &selectors[index]);

		fscanf(circuitDescription, "%c%*[ \t\n\v\f\r]", &output);


		int input1 = GETVALUE(inputs[0]),
				input2 = GETVALUE(inputs[1]),
				input3 = GETVALUE(inputs[2]),
				input4 = GETVALUE(inputs[3]),
				input5 = GETVALUE(inputs[4]),
				input6 = GETVALUE(inputs[5]),
				input7 = GETVALUE(inputs[6]),
				input8 = GETVALUE(inputs[7]),
				input9 = GETVALUE(inputs[8]),
				input10 = GETVALUE(inputs[9]),
				input11 = GETVALUE(inputs[10]),
				input12 = GETVALUE(inputs[11]),
				input13 = GETVALUE(inputs[12]),
				input14 = GETVALUE(inputs[13]),
				input15 = GETVALUE(inputs[14]),
				input16 = GETVALUE(inputs[15]),

		    selector1 = GETVALUE(selectors[0]),
		    selector2 = GETVALUE(selectors[1]),
		    selector3 = GETVALUE(selectors[2]),
		    selector4 = GETVALUE(selectors[3]);


		if (!selector1 && !selector2 && !selector3 && !selector4)
				values[TOINDEX(output)] = input1;

		else if (!selector1 && !selector2 && !selector3 && selector4)
				values[TOINDEX(output)] = input2;

		else if (!selector1 && !selector2 && selector3 && selector4)
				values[TOINDEX(output)] = input3;

		else if (!selector1 && !selector2 && selector3 && !selector4)
				values[TOINDEX(output)] = input4;

		else if (!selector1 && selector2 && selector3 && !selector4)
				values[TOINDEX(output)] = input5;

		else if (!selector1 && selector2 && selector3 && selector4)
				values[TOINDEX(output)] = input6;

		else if (!selector1 && selector2 && !selector3 && selector4)
				values[TOINDEX(output)] = input7;

		else if (!selector1 && selector2 && !selector3 && !selector4)
				values[TOINDEX(output)] = input8;

		else if (selector1 && selector2 && !selector3 && !selector4)
				values[TOINDEX(output)] = input9;

		else if (selector1 && selector2 && !selector3 && selector4)
				values[TOINDEX(output)] = input10;

		else if (selector1 && selector2 && selector3 && selector4)
				values[TOINDEX(output)] = input11;

		else if (selector1 && selector2 && selector3 && !selector4)
				values[TOINDEX(output)] = input12;

		else if (selector1 && !selector2 && selector3 && !selector4)
				values[TOINDEX(output)] = input13;

		else if (selector1 && !selector2 && selector3 && selector4)
				values[TOINDEX(output)] = input14;

		else if (selector1 && !selector2 && !selector3 && selector4)
				values[TOINDEX(output)] = input15;

		else
				values[TOINDEX(output)] = input16;
	}


void Multiplexer_Multiplex(FILE* circuitDescription, int* values)
	{
		int numberOfArguments;

		fscanf(circuitDescription, "%d%*[ \t\n\v\f\r]", &numberOfArguments);
		
		switch(numberOfArguments)
			{
				case 2: Multiplexer_Multiplex2to1(circuitDescription, values);
								break;
				case 4: Multiplexer_Multiplex4to1(circuitDescription, values);
								break;
				case 8: Multiplexer_Multiplex8to1(circuitDescription, values);
								break;
				case 16: Multiplexer_Multiplex16to1(circuitDescription, values);
								break;
			}
	}
