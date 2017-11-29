#include "fourth.h"

struct _Matrix_
	{
		int numberOfRows,
				numberOfColumns; 
		int** table; 
	};

Matrix* Matrix_construct(int numberOfRows, int numberOfColumns)
	{
		Matrix* matrix = (Matrix*)malloc(sizeof(Matrix) );
		matrix->numberOfRows = numberOfRows;
		matrix->numberOfColumns = numberOfColumns; 
		matrix->table = (int**)malloc(sizeof(int*) * numberOfRows); 
		int currentRow;

		for (currentRow = 0; currentRow < numberOfRows; currentRow++)
				matrix->table[currentRow] = (int*)malloc(sizeof(int) * numberOfColumns);

		return matrix;
	}

Matrix* Matrix_add(Matrix* addend1, Matrix* addend2)
	{
		Matrix* sum = Matrix_construct(addend1->numberOfRows, addend1->numberOfColumns);
		int currentRow,
				currentColumn;

		for (currentRow = 0; currentRow < addend1->numberOfRows; currentRow++)
				for (currentColumn = 0; currentColumn < addend1->numberOfColumns; currentColumn++)
						sum->table[currentRow][currentColumn] = addend1->table[currentRow][currentColumn] + addend2->table[currentRow][currentColumn];

		return sum; 
	}

void Matrix_print(Matrix* matrix)
	{
		int currentRow,
				currentColumn;

		for (currentRow = 0; currentRow < matrix->numberOfRows; currentRow++)
				for (currentColumn = 0; currentColumn < matrix->numberOfColumns; currentColumn++)
					{
						if (currentColumn == matrix->numberOfColumns - 1)
								printf("%d\n", matrix->table[currentRow][currentColumn]); 
						else 
								printf("%d\t", matrix->table[currentRow][currentColumn]); 
					}
	}

void Matrix_destroy(Matrix* matrix)
	{
		int currentRow;

		for (currentRow = 0; currentRow < matrix->numberOfRows; currentRow++)
				free(matrix->table[currentRow]);

		free(matrix->table);
		free(matrix); 
	}

int main(int argumentCount, char** argumentVector)
	{
		FILE* textFile = fopen(argumentVector[1], "r");

		if (!textFile || fgetc(textFile) == EOF)
      {
				printf("error\n"); 
				fclose(textFile);

        return 0;
      }	
		else
				rewind(textFile);

		int numberOfRows,
				numberOfColumns;

		fscanf(textFile, "%d\t%d\n", &numberOfRows, &numberOfColumns);

		if (numberOfRows == 0 && numberOfColumns == 0)
			{
				printf("\n");

				return 0;
			}

		Matrix* addend1 = Matrix_construct(numberOfRows, numberOfColumns),
					* addend2 = Matrix_construct(numberOfRows, numberOfColumns);

		int currentRow,
				currentColumn;

		for (currentRow = 0; currentRow < numberOfRows; currentRow++)
				for (currentColumn = 0; currentColumn < numberOfColumns; currentColumn++)
						fscanf(textFile, "%d", &(addend1->table[currentRow][currentColumn]) );			

		for (currentRow = 0; currentRow < numberOfRows; currentRow++)
				for (currentColumn = 0; currentColumn < numberOfColumns; currentColumn++)
						fscanf(textFile, "%d", &(addend2->table[currentRow][currentColumn]) );	

		Matrix* sum = Matrix_add(addend1, addend2);

		Matrix_print(sum);
	
		Matrix_destroy(addend1);
		Matrix_destroy(addend2);
		Matrix_destroy(sum);	
		fclose(textFile);

		return 0;
	}
