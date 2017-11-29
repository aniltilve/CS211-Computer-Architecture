#include <stdio.h>
#include <stdlib.h>

#ifndef EIGHTH_H_
#define EIGHTH_H_

typedef struct _Node_ Node;
Node* Node_Construct(int element, Node* leftChild, Node* rightChild);
void Node_Destroy(Node* node); 

Node* BinarySearchTree_Insert(Node* root, int element, int currentHeight); 
void BinarySearchTree_Search(Node* root, int element, int currentHeight); 

int main(int argumentCount, char** argumentVector); 

#endif //EIGHTH_H_
