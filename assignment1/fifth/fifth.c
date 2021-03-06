#include "fifth.h"

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
				matrix->table[currentRow] = (int*)calloc(numberOfColumns, sizeof(int) );

		return matrix;
	}

Matrix* Matrix_multiply(Matrix* multiplicand, Matrix* multiplier)
	{
		Matrix* product = Matrix_construct(multiplicand->numberOfRows, multiplier->numberOfColumns);
		int currentRow,
				currentColumn,		
				currentInner; 

		for (currentRow = 0; currentRow < product->numberOfRows; currentRow++)
				for (currentColumn = 0; currentColumn < product->numberOfColumns; currentColumn++)
						for (currentInner = 0; currentInner < multiplicand->numberOfColumns; currentInner++)
								product->table[currentRow][currentColumn] += multiplicand->table[currentRow][currentInner] * multiplier->table[currentInner][currentColumn];

		return product; 
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

		Matrix* multiplicand = Matrix_construct(numberOfRows, numberOfColumns);

		int currentRow,
				currentColumn;

		for (currentRow = 0; currentRow < numberOfRows; currentRow++)
				for (currentColumn = 0; currentColumn < numberOfColumns; currentColumn++)
						fscanf(textFile, "%d", &(multiplicand->table[currentRow][currentColumn]) );	

		fscanf(textFile, "%d\t%d\n", &numberOfRows, &numberOfColumns);

		Matrix* multiplier = Matrix_construct(numberOfRows, numberOfColumns);

		for (currentRow = 0; currentRow < numberOfRows; currentRow++)
				for (currentColumn = 0; currentColumn < numberOfColumns; currentColumn++)
						fscanf(textFile, "%d", &(multiplier->table[currentRow][currentColumn]) );	

		Matrix* product = Matrix_multiply(multiplicand, multiplier);

		Matrix_print(product);
	
		Matrix_destroy(multiplicand);
		Matrix_destroy(multiplier);
		Matrix_destroy(product);	
		fclose(textFile);

		return 0;
	}
