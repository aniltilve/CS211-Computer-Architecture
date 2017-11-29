#include <stdio.h>
#include <stdlib.h>

#ifndef SECOND_H_
#define SECOND_H_

typedef struct _Node_ Node;
Node* Node_Construct(int element, Node* nextNode);
void Node_Destroy(Node* node); 

Node* LinkedList_Insert(Node* head, int element);
Node* LinkedList_Delete(Node* head, int element); 
void LinkedList_Print(Node* head);

int main(int argumentCount, char** argumentVector); 

#endif //SECOND_H_
