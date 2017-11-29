#include "eighth.h"

struct _Node_ 
  {
    int element;
    Node* leftChild,
        * rightChild; 
  };

Node* Node_Construct(int element, Node* leftChild, Node* rightChild)
  {
     Node* newNode = (Node*)malloc(sizeof(Node) );
     newNode->element = element;
     newNode->leftChild = leftChild; 
     newNode->rightChild = rightChild; 

     return newNode; 
  }

void Node_Destroy(Node* node)
  {
		if (!node)
				return; 

    if (node->rightChild)
      	Node_Destroy(node->rightChild); 
    if (node->leftChild)
      	Node_Destroy(node->leftChild); 

    free(node); 
  }


Node* BinarySearchTree_Insert(Node* root, int element, int currentHeight)
	{
    if (!root)
      {
				root = Node_Construct(element, NULL, NULL);
				printf("inserted %d\n", currentHeight); 
      }
    else if (element < root->element)
        root->leftChild = BinarySearchTree_Insert(root->leftChild, element, ++currentHeight); 
    else if (element > root->element)
        root->rightChild = BinarySearchTree_Insert(root->rightChild, element, ++currentHeight); 
    else
    		printf("duplicate\n");

		return root; 
  }

void BinarySearchTree_Search(Node* root, int element, int currentHeight) 
  {
    if (!root)
        printf("absent\n"); 
    else if (element < root->element)
        BinarySearchTree_Search(root->leftChild, element, ++currentHeight); 
    else if (element > root->element)
        BinarySearchTree_Search(root->rightChild, element, ++currentHeight); 
		else 
        printf("present %d\n", currentHeight);
  }


int main(int argumentCount, char** argumentVector)
  {
    FILE* textFile = fopen(argumentVector[1], "r"); 

    if (!textFile)
      {
				printf("error\n"); 

        return 0;
      }

		Node* root = NULL; 
	  int argument; 
		char operation;

   	while (fscanf(textFile, "%c\t%d\n", &operation, &argument) != EOF)
			{	
				if (operation == 'i')
						root = BinarySearchTree_Insert(root, argument, 1);
				else if (operation == 's')
						BinarySearchTree_Search(root, argument, 1);
				else 
						printf("error\n");
			}

    Node_Destroy(root);
    fclose(textFile);

    return 0;  
  }
