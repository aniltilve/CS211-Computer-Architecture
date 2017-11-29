#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "statGenerator.h"


int main(int argumentCount, char** argumentVector)
	{
		//Get the mapping file and check it for validity

		FILE *mappingFile = fopen(argumentVector[1], "r");


		if (!mappingFile || argumentCount != 2)
			{
				printf("invalid input\n");

				return 0; 
			}

		char dictionaryFileName[512] = "",
				 dataFileName[512] = "";
		unsigned long currentLine = 1; 

		//main loop
		while (fscanf(mappingFile, "%s %s\n", &dictionaryFileName[0], &dataFileName[0]) != EOF)
			{
				StatGenerator* statGenerator = StatGenerator_Construct(&dictionaryFileName[0], &dataFileName[0]);
			  StatGenerator_UpdateStatistics(statGenerator);
				StatGenerator_ConstructOutputFile(statGenerator, currentLine);
				StatGenerator_Destroy(statGenerator);
				currentLine++;
			}

		fclose(mappingFile);
		return 0;
	}
