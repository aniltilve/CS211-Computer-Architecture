#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BinarySearchTree.h"


Node* Node_Construct(char* word)
  {
    Node* new = (Node*)malloc(sizeof(Node) );
    new->word = strdup(word);

		new->occurrenceCount = 0;
		new->prefixCount = 0;

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

		free(existent);
	}


Node* BinarySearchTree_Add(Node* root, char* new)
	{
    if (!root)
				root = Node_Construct(new);

    else if (strcmp(new, root->word) < 0)
        root->leftChild = BinarySearchTree_Add(root->leftChild, new); 

    else if (strcmp(new, root->word) > 0)
        root->rightChild = BinarySearchTree_Add(root->rightChild, new); 

		return root; 
  }


Node* BinarySearchTree_Get(Node* root, char* target) 
  {
    if (!root)
        return NULL;

    else if (strcmp(target, root->word) < 0)
        return BinarySearchTree_Get(root->leftChild, target); 

    else if (strcmp(target, root->word) > 0)
        return BinarySearchTree_Get(root->rightChild, target); 
		
		return root; 
  }


void BinarySearchTree_IncrementPrefixCounts(Node* root, char* comparable)
	{
		if (!root)
				return; 

		if (strstr(root->word, comparable) - root->word == 0 && strlen(comparable) < strlen(root->word) ) 
				root->prefixCount++;				

    BinarySearchTree_IncrementPrefixCounts(root->leftChild, comparable);
		BinarySearchTree_IncrementPrefixCounts(root->rightChild, comparable);
	}
