#include <stdio.h> 
#include <stdlib.h>

#ifndef FOURTH_H_
#define FOURTH_H_

typedef struct _Matrix_ Matrix; 

Matrix* Matrix_construct(int numberOfRows, int NumberOfColumns);
Matrix* Matrix_multiply(Matrix* multiplicand, Matrix* multiplier);
void Matrix_print(Matrix* matrix);
void Matrix_destroy(Matrix* matrix);

int main(int argumentCount, char** argumentVector);

#endif //FOURTH_H_
