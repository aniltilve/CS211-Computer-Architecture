#include "seventh.h"
#include <string.h>

int main(int argumentCount, char** argumentVector)
  {
		if (argumentCount == 1)
			{
				printf("error\n");

				return 0;
			}

    int currentArgument;

    for (currentArgument = 1; currentArgument < argumentCount; currentArgument++)
        printf("%c", *(argumentVector[currentArgument] + strlen(argumentVector[currentArgument]) - 1));

    printf("\n");

    return 0;
  }
