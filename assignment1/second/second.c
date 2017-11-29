#include "second.h"

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
		if (!node)
				return;
		if (node->nextNode)
				Node_Destroy(node->nextNode);

    free(node); 
  }


Node* LinkedList_Insert(Node* head, int element)
  {
    if (!head || element < head->element)
        head = Node_Construct(element, head);
		else if (element == head->element)
			{}
    else
      	head->nextNode = LinkedList_Insert(head->nextNode, element);

		return head;
  }

Node* LinkedList_Delete(Node* head, int element)
  {
		if (!head)
			{}
		else if (element == head->element)
				head = head->nextNode;
		else 
				head->nextNode = LinkedList_Delete(head->nextNode, element);

		return head;
	}


void LinkedList_Print(Node* head)
  {
		if (!head)
				printf("\n");
		else
			{
				printf("%d\t", head->element);
				LinkedList_Print(head->nextNode);
			}
  }


int main(int argumentCount, char** argumentVector)
  {
    FILE* textFile = fopen(argumentVector[1], "r"); 

    if (!textFile)
      {
				printf("error\n"); 

        return 0;
      }

		if (fgetc(textFile) == EOF)
			{
				printf("\n");

				return 0;
			}
		else 
				rewind(textFile);

    Node* head = NULL;

		int status = 0,
				argument = 0;
		char operation = '\0'; 

   	do 
			{
				status = fscanf(textFile, "%c\t%d\n", &operation, &argument);
				
				if (operation == 'i')
						head = LinkedList_Insert(head, argument);
				else if (operation == 'd')
						head = LinkedList_Delete(head, argument);
				else
					{
						printf("error\n");

						return 0;
					}
			}
		while (status != EOF);

		LinkedList_Print(head);

    Node_Destroy(head);
    fclose(textFile);

    return 0;  
  }
