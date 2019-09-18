#include <stdio.h>
#include <stdlib.h>

void rotate(int** matrix, int matrixSize, int* matrixColSize){
    printf("hello");
	matrix[0][0] = 0; 
	//遍历i,j
	for()
	//列出4数组

	//旋转4数组
}

int main(){
	int * matrixColSize;
	//int ** p;
	int a[3] = {1,2,3};
	int b[3] = {4,5,6};
	int c[3] = {7,8,9};
	int *matrix [3] = {
		(int[]){1,2,3}, 
		(int[]){4,5,6}, 
		(int[]){7,8,9}
		};
	//p = matrix;
	matrixColSize = (int*)malloc(sizeof(int));
	* matrixColSize = 3;
	rotate(matrix, 3, matrixColSize);
	return 0;
}