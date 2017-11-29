#include <stdio.h>
#include <stdlib.h>

#ifndef NINTH_H_
#define NINTH_H_

typedef struct _Node_ Node;
Node* Node_Construct(int element, Node* leftChild, Node* rightChild);
void Node_Destroy(Node* node); 

int BinarySearchTree_GetInOrderSuccessor(Node* root); 
Node* BinarySearchTree_DeleteInOrderSuccessor(Node* root, int element);
Node* BinarySearchTree_Insert(Node* root, int element, int currentHeight); 
Node* BinarySearchTree_Delete(Node* root, int element); 
void BinarySearchTree_Search(Node* root, int element, int currentHeight); 

int main(int argumentCount, char** argumentVector);

#endif //NINTH_H_
