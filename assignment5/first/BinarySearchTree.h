#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

typedef struct _Node_ Node;

struct _Node_ 
  {
    char* word;

		unsigned long occurrenceCount, 
				          prefixCount;

    Node* leftChild,
        * rightChild; 
  };

Node* Node_Construct(char* word);
void Node_Destroy(Node* existent); 

Node* BinarySearchTree_Add(Node* root, char* new); 
Node* BinarySearchTree_Get(Node* root, char* target); 
void BinarySearchTree_IncrementPrefixCounts(Node* root, char* comparable);

#endif //BINARYSEARCHTREE_H_
