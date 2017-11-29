#include "third.h" 

struct _Node_ 
  {
    int element;
    Node* nextNode; 
  };

Node* Node_Construct(int element, Node* nextNode)
  {
     Node* newNode = (Node*)malloc(sizeof(Node) );
     
     newNode->element = element;
     newNode->nextNode = nextNode; 

     return newNode; 
  }

void Node_Destroy(Node* node)
  {
		if(!node)
				return; 

		if (node->nextNode)
				Node_Destroy(node->nextNode); 

    free(node); 
  }

Node* HashTable_Insert(Node* head, int element)
  {
    if (!head || element < head->element) 
			{
				printf("inserted\n"); 

        return Node_Construct(element, head); 
			}
		else if (element == head->element)
				printf("duplicate\n"); 
    else
      	head->nextNode = HashTable_Insert(head->nextNode, element);

		return head;
  }

void HashTable_Search(Node* head, int element)
  {
		if (!head)
				printf("absent\n"); 
		else if (element == head->element)
				printf("present\n");
		else 
				HashTable_Search(head->nextNode, element);
  }

int main(int argumentCount, char** argumentVector)
	{
		FILE* textFile = fopen(argumentVector[1], "r"); 

    if (!textFile)
      {
				printf("error\n"); 

        return 0;
      }

    Node* hashTable[10000];

		int index;

		for (index = 0; index < 10000; index++)
				hashTable[index] = NULL;

		int argument,
				hashCode; 
		char operation; 

   	while (fscanf(textFile, "%c\t%d\n", &operation, &argument) != EOF)
			{
				if (operation == 'i')
					{
						hashCode = abs(argument) % 10000;  
						hashTable[hashCode] = HashTable_Insert(hashTable[hashCode], argument);
					}
				else if (operation == 's')
					{
						hashCode = abs(argument) % 10000;
						HashTable_Search(hashTable[hashCode], argument);
					}
				else  
						printf("error\n");
			}

		rewind(textFile);

		while (fscanf(textFile, "%c\t%d\n", &operation, &argument) != EOF)
			{
				if (operation == 'i')
					{
						hashCode = abs(argument) % 10000;  
						Node_Destroy(hashTable[hashCode]); 
					} 
			}

		fclose(textFile);

		return 0; 
	}
