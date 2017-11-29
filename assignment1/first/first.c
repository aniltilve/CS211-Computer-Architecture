#include "first.h"

int isPrime(int argument)
  {
    int testNumber; 

		for (testNumber = 2; testNumber * testNumber <= argument; testNumber++)
        if (argument % testNumber == 0)
	    			return 0;

    return 1;
  }

int main(int argumentCount, char** argumentVector)
  {
    if (argumentVector[1] == NULL)
    {
			printf("error\n");

      return 0;
    }

    int result = isPrime(atoi(argumentVector[1]));

    if (result == 1)
        printf("yes\n");
    else 
        printf("no\n");

    return 0; 
  }
