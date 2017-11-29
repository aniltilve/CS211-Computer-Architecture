#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binarySearchTree.h"


Node* Node_Construct(char* word)
  {
    Node* new = (Node*)malloc(sizeof(Node) );
    new->word = calloc(512, 1);
		strcpy(new->word, word);

		new->numberOfOccurrences = 0;
		new->numberOfSuperwords = 0;

    new->leftChild = NULL; 
    new->rightChild = NULL; 

    return new; 
  }


void Node_Destroy(Node* existent)
	{
		if (!existent)
				return;

		if (existent->leftChild)
				Node_Destroy(existent->leftChild);
		if (existent->rightChild)
				Node_Destroy(existent->rightChild);

		free(existent->word);
		free(existent);
	}


Node* BinarySearchTree_Put(Node* root, char* newWord)
	{
    if (!root)
				root = Node_Construct(newWord);

    else if (strcmp(newWord, root->word) == -1)
        root->leftChild = BinarySearchTree_Put(root->leftChild, newWord); 

    else if (strcmp(newWord, root->word) == 1)
        root->rightChild = BinarySearchTree_Put(root->rightChild, newWord); 

		return root; 
  }


Node* BinarySearchTree_Get(Node* root, char* target) 
  {
    if (!root)
        return NULL;

    else if (strcmp(target, root->word) == -1)
        return BinarySearchTree_Get(root->leftChild, target); 

    else if (strcmp(target, root->word) == 1)
        return BinarySearchTree_Get(root->rightChild, target); 
		
		return root; 
  }


void BinarySearchTree_UpdateNumberOfSuperwords(Node* root, char* comparable)
	{
		if (!root)
				return; 

		if (strstr(root->word, root->word) && strlen(root->word) < strlen(comparable) ) 
				root->numberOfSuperwords++;				

    BinarySearchTree_UpdateNumberOfSuperwords(root->leftChild, comparable);
		BinarySearchTree_UpdateNumberOfSuperwords(root->leftChild, comparable);
	}
