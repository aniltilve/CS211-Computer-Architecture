#include "sixth.h"

int main(int argumentCount, char** argumentVector)
  {
		if (argumentCount == 1)
			{
				printf("error\n");

				return 0;
			}

    int currentArgument;

    for (currentArgument = 1; currentArgument < argumentCount; currentArgument++)
        printf("%c", *argumentVector[currentArgument]);

    printf("\n");

    return 0;
  }
