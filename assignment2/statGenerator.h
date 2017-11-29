#include "binarySearchTree.h"

#ifndef STATGENERATOR_H_
#define STATGENERATOR_H_

typedef struct _StatGenerator_ StatGenerator; 

struct _StatGenerator_
	{
		FILE* dictionaryFile,
				*	dataFile;
		Node* words;
	}; 

StatGenerator* StatGenerator_Construct(char* dictionaryFileName, char* dataFileName);
void StatGenerator_UpdateStatistics(StatGenerator* existingStatGenerator);
void StatGenerator_ConstructOutputFile(StatGenerator* existingStatGenerator, unsigned long currentLine);
void StatGenerator_EditOutputFile(Node* root, FILE* outputFile);
void StatGenerator_Destroy(StatGenerator* existingStatGenerator);

#endif //STATGENERATOR_H_
