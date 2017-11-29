#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "statGenerator.h"

void String_ConvertToLowerCase(char* existingString)
	{
		if (!existingString)
				return; 

		int currentIndex;

		for (currentIndex = 0; existingString[currentIndex]; currentIndex++)
				existingString[currentIndex] = (char)tolower( (int)existingString[currentIndex]);
	}


StatGenerator* StatGenerator_Construct(char* dictionaryFileName, char* dataFileName)
	{
		//Initialize everything
		StatGenerator* newStatGenerator = (StatGenerator*)malloc(sizeof(StatGenerator) );

		newStatGenerator->dictionaryFile = fopen(dictionaryFileName, "r");
		newStatGenerator->dataFile = fopen(dataFileName, "r");
		newStatGenerator->words = NULL;

		char word[512] = ""; 
	  int status; 

		//Scan the dictionary file and copy words into the tree
		while ( (status = fscanf(newStatGenerator->dictionaryFile, "%511[a-zA-Z]", &word[0]) ) != EOF)
			{
				if (status == 1)
					{
						String_ConvertToLowerCase(&word[0]);
						newStatGenerator->words = BinarySearchTree_Put(newStatGenerator->words, &word[0]);
					}
		
    		if (fscanf(newStatGenerator->dictionaryFile, "%511[^a-zA-Z]", &word[0]) != 1)
						continue; 
			}
		
		return newStatGenerator;
	}


void StatGenerator_UpdateStatistics(StatGenerator* existingStatGenerator)
	{
		char word[512] = ""; 
		Node* target = NULL;
		int status; 

		//Scan the data file for occurrences and superwords and update the statistics for each dictionary word in the tree
		while ( (status = fscanf(existingStatGenerator->dataFile, "%511[a-zA-Z]", &word[0]) ) != EOF)
			{
				if (status == 1)
					{
						String_ConvertToLowerCase(&word[0]);

						if ( (target = BinarySearchTree_Get(existingStatGenerator->words, &word[0]) ) )
								target->numberOfOccurrences++;
				
						BinarySearchTree_UpdateNumberOfSuperwords(existingStatGenerator->words, &word[0]);
					}

				if (fscanf(existingStatGenerator->dataFile, "%511[^a-zA-Z]", &word[0]) != 1)
						continue; 
			}
	}


void StatGenerator_ConstructOutputFile(StatGenerator* existingStatGenerator, unsigned long currentLine)
	{
		//Initialize the file
		char* fileName = (char*)calloc(512, 1),
				 lineNumber[256] = ""; 
		
		fileName[0] = 'o';
		fileName[1] = 'u';
		fileName[2] = 't';

		//Convert the line number to a string and append it to the file name
		sprintf(&lineNumber[0], "%lu", currentLine);

		fileName = strcat(fileName, &lineNumber[0]);
		fileName = strcat(fileName, ".txt");

		FILE* output = fopen(fileName, "w");

		StatGenerator_EditOutputFile(existingStatGenerator->words, output);

		free(fileName);

		fclose(output);
	}


void StatGenerator_EditOutputFile(Node* root, FILE* outputFile)
	{
		//Perform in-order traversal of the tree in order to write the words in lexicographic order
		if (!root) 
			return; 

		StatGenerator_EditOutputFile(root->leftChild, outputFile);
		
		
		fprintf(outputFile, "%s %lu %lu\n", root->word, root->numberOfOccurrences, root->numberOfSuperwords);

		StatGenerator_EditOutputFile(root->rightChild, outputFile);
	}


void StatGenerator_Destroy(StatGenerator* existingStatGenerator)
	{
		fclose(existingStatGenerator->dictionaryFile);
		fclose(existingStatGenerator->dataFile);

		Node_Destroy(existingStatGenerator->words);

		free(existingStatGenerator);
	}
