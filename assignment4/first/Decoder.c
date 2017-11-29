#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Decoder.h"

#define TOINDEX(x) (x > 90? x - 71 : x - 65)
#define GETVALUE(y) (y > 49? values[TOINDEX(y)] : y - 48 )


void Decoder_Decode1to2(FILE* circuitDescription, int* values)
	{
		char input,
				 output;

		fscanf(circuitDescription, "%c%*[ \t\n\v\f\r]", &input);
	

		fscanf(circuitDescription, "%c%*[ \t\n\v\f\r]", &output);
		values[TOINDEX(output)] = !GETVALUE(input);

		fscanf(circuitDescription, "%c%*[ \t\n\v\f\r]", &output);
		values[TOINDEX(output)] = GETVALUE(input);
	}


void Decoder_Decode2to4(FILE* circuitDescription, int* values)
	{
		char inputs[2],
				 output;
		int index;


		for (index = 0; index < 2; index++)
				fscanf(circuitDescription, "%c%*[ \t\n\v\f\r]", &inputs[index]);

		
		int value1 = GETVALUE(inputs[0]),
				value2 = GETVALUE(inputs[1]);


		fscanf(circuitDescription, "%c%*[ \t\n\v\f\r]", &output);
		values[TOINDEX(output)] = (!value1) & (!value2);

		fscanf(circuitDescription, "%c%*[ \t\n\v\f\r]", &output);
		values[TOINDEX(output)] = (!value1) & value2;

		fscanf(circuitDescription, "%c%*[ \t\n\v\f\r]", &output);
		values[TOINDEX(output)] = value1 & value2;

		fscanf(circuitDescription, "%c%*[ \t\n\v\f\r]", &output);
		values[TOINDEX(output)] = value1 & (!value2);
	}


void Decoder_Decode3to8(FILE* circuitDescription, int* values)
	{
		char inputs[3],
				 output;
		int index;


		for (index = 0; index < 3; index++)
				fscanf(circuitDescription, "%c%*[ \t\n\v\f\r]", &inputs[index]);


		int value1 = GETVALUE(inputs[0]),
				value2 = GETVALUE(inputs[1]),
				value3 = GETVALUE(inputs[2]);


		fscanf(circuitDescription, "%c%*[ \t\n\v\f\r]", &output);
		values[TOINDEX(output)] = (!value1) & (!value2) & (!value3);

		fscanf(circuitDescription, "%c%*[ \t\n\v\f\r]", &output);
		values[TOINDEX(output)] = (!value1) & (!value2) & value3;

		fscanf(circuitDescription, "%c%*[ \t\n\v\f\r]", &output);
		values[TOINDEX(output)] = (!value1) & value2 & value3;

		fscanf(circuitDescription, "%c%*[ \t\n\v\f\r]", &output);
		values[TOINDEX(output)] = (!value1) & value2 & (!value3);

		fscanf(circuitDescription, "%c%*[ \t\n\v\f\r]", &output);
		values[TOINDEX(output)] = value1 & value2 & (!value3);

		fscanf(circuitDescription, "%c%*[ \t\n\v\f\r]", &output);
		values[TOINDEX(output)] = value1 & value2 & value3;

		fscanf(circuitDescription, "%c%*[ \t\n\v\f\r]", &output);
		values[TOINDEX(output)] = value1 & (!value2) & value3;

		fscanf(circuitDescription, "%c%*[ \t\n\v\f\r]", &output);
		values[TOINDEX(output)] = value1 & (!value2) & (!value3);
	}


void Decoder_Decode4to16(FILE* circuitDescription, int* values)
	{
		char inputs[4],
				 output;
		int index;


		for (index = 0; index < 4; index++)
				fscanf(circuitDescription, "%c%*[ \t\n\v\f\r]", &inputs[index]);


		int value1 = GETVALUE(inputs[0]),
				value2 = GETVALUE(inputs[1]),
				value3 = GETVALUE(inputs[2]),
				value4 = GETVALUE(inputs[3]);


		fscanf(circuitDescription, "%c%*[ \t\n\v\f\r]", &output);
		values[TOINDEX(output)] = (!value1) & (!value2) & (!value3) & (!value4);

		fscanf(circuitDescription, "%c%*[ \t\n\v\f\r]", &output);
		values[TOINDEX(output)] = (!value1) & (!value2) & (!value3) & value4;

		fscanf(circuitDescription, "%c%*[ \t\n\v\f\r]", &output);
		values[TOINDEX(output)] = (!value1) & (!value2) & value3 & value4;

		fscanf(circuitDescription, "%c%*[ \t\n\v\f\r]", &output);
		values[TOINDEX(output)] = (!value1) & (!value2) & value3 & (!value4);

		fscanf(circuitDescription, "%c%*[ \t\n\v\f\r]", &output);
		values[TOINDEX(output)] = (!value1) & value2 & value3 & (!value4);

		fscanf(circuitDescription, "%c%*[ \t\n\v\f\r]", &output);
		values[TOINDEX(output)] = (!value1) & value2 & value3 & value4;

		fscanf(circuitDescription, "%c%*[ \t\n\v\f\r]", &output);
		values[TOINDEX(output)] = (!value1) & value2 & (!value3) & value4;

		fscanf(circuitDescription, "%c%*[ \t\n\v\f\r]", &output);
		values[TOINDEX(output)] = (!value1) & value2 & (!value3) & (!value4); 


		fscanf(circuitDescription, "%c%*[ \t\n\v\f\r]", &output);
		values[TOINDEX(output)] = value1 & value2 & (!value3) & (!value4); 

		fscanf(circuitDescription, "%c%*[ \t\n\v\f\r]", &output);
		values[TOINDEX(output)] = value1 & value2 & (!value3) & value4;

		fscanf(circuitDescription, "%c%*[ \t\n\v\f\r]", &output);
		values[TOINDEX(output)] = value1 & value2 & value3 & value4;

		fscanf(circuitDescription, "%c%*[ \t\n\v\f\r]", &output);
		values[TOINDEX(output)] = value1 & value2 & value3 & (!value4);

		fscanf(circuitDescription, "%c%*[ \t\n\v\f\r]", &output);
		values[TOINDEX(output)] = value1 & (!value2) & value3 & (!value4);

		fscanf(circuitDescription, "%c%*[ \t\n\v\f\r]", &output);
		values[TOINDEX(output)] = value1 & (!value2) & value3 & value4;

		fscanf(circuitDescription, "%c%*[ \t\n\v\f\r]", &output);
		values[TOINDEX(output)] = value1 & (!value2) & (!value3) & value4;

		fscanf(circuitDescription, "%c%*[ \t\n\v\f\r]", &output);
		values[TOINDEX(output)] = value1 & (!value2) & (!value3) & (!value4);
	}


void Decoder_Decode(FILE* circuitDescription, int* values)
	{
		int numberOfArguments;

		fscanf(circuitDescription, "%d%*[ \t\n\v\f\r]", &numberOfArguments);
		
		switch(numberOfArguments)
			{
				case 1: Decoder_Decode1to2(circuitDescription, values);
								break;
				case 2: Decoder_Decode2to4(circuitDescription, values);
								break;
				case 3: Decoder_Decode3to8(circuitDescription, values);
								break;
				case 4: Decoder_Decode4to16(circuitDescription, values);
								break;
				default: 
								break;
			}
	}
