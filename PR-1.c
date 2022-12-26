#include <stdio.h>

struct Matrix{
int index;
int matrix_arr[100][100];
};

void initialize (struct Matrix *m1);
void Create(struct Matrix *m1, int rows, int columns);
void add_Matrix(struct Matrix m1,struct Matrix m2, int rows, int columns);
void mul_Matrix(struct Matrix m1,struct Matrix m2, int rows, int columns);

int main(){
    int no_of_rows, no_of_columns;
    printf("Enter the number of rows : ");
    scanf("%d", &no_of_rows);
    printf("Enter the number of columns : ");
    scanf("%d", &no_of_columns);

	struct Matrix M1,M2;
	initialize(&M1);
	initialize(&M2);
	
	Create(&M1, no_of_rows, no_of_columns);    
	Create(&M2, no_of_rows, no_of_columns);
	
	add_Matrix(M1, M2, no_of_rows, no_of_columns);
    mul_Matrix(M1, M2, no_of_rows, no_of_columns);
	return 0;
}

void initialize (struct Matrix *m1){
	m1->index = -1;
}

void Create(struct Matrix *m1, int rows, int columns){
	printf("Enter the elements for array : \n");
	for(int i = 0; i < (rows); i++){
		for(int j = 0; j<(columns); j++){
			scanf("%d", &(m1->matrix_arr[i][j]));
			m1->index += 1;
			}
		m1->index += 1;
		}
	for(int i = 0; i < (rows); i++){
		for(int j = 0; j<(columns); j++){
			printf( "%d " ,(m1->matrix_arr[i][j]));
			}
		}
        printf("\n");
}

void add_Matrix(struct Matrix m1,struct Matrix m2, int rows, int columns){
    printf("\nThe addition of two matrices are : \n");
    for(int i = 0; i < (rows); i++){
		for(int j = 0; j<(columns); j++){
                printf( "%d " ,m1.matrix_arr[i][j] + m2.matrix_arr[i][j]);
			}
		}
    printf("\n");
}

void mul_Matrix(struct Matrix m1,struct Matrix m2, int rows, int columns){
    printf("\nThe multiplication of two matrices are : \n");
    for(int i = 0; i < (rows); i++){
		for(int j = 0; j<(columns); j++){
                printf( "%d " ,m1.matrix_arr[i][j] * m2.matrix_arr[i][j]);
			}
		}
    printf("\n");
}