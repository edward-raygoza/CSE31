
#include <stdio.h>
#include <malloc.h>

int** matMult(int **a, int **b, int size){
	// (4) Implement your matrix multiplication here. You will need to create a new matrix to store the product.
	int **arr2 = (int**)malloc(size * sizeof(int*));

	for(int i = 0; i < size; i++){
		*(arr2 + i)=(int*)malloc(size* sizeof(int));
			for(int j =0; j<size;j++){
				*(*(arr2 + i)+j)=0;
			}
	}
	for(int i =0; i < size; i++){
		for(int j =0; j<size; j++){
			for(int k =0; k < size;k++){
				*(*(arr2+i)+j)+= *(*(a+i)+k) * (*(*(b+k)+j));
			}
		}
	}
return arr2;
}



void printArray(int **arr, int n){
	// (2) Implement your printArray function here
	for(int i =0; i<n;i++){
		for(int j =0; j<n; j++){
			printf("%d ",*(*(arr + i)+j));
		}
		printf("\n ");
	}
}

int main() {
	int n = 5;
	//int n = 0;
	//int **matA, **matB, **matC;
	// (1) Define 2 n x n arrays (matrices). 
	int **matA=(int**)malloc(n *sizeof(int*));

	for(int i = 0;i<n;i++){
		*(matA + i)=(int*)malloc(n* sizeof(int));
	for(int j = 0; j<n;j++){
		*(*(matA+i)+j)=i+j;
	}
	}
	//(3) Call printArray to print out the 2 array here
	int **matB = (int**)malloc(n * sizeof(int*));
		for(int i = 0; i<n;i++){
			*(matB + i)= (int*)malloc(n*sizeof(int));
		for(int j=0; j<n;j++){
			*(*(matB+i)+j)=i+j;
		}
		}
	printArray(matA,n);
	printf("\n ");
	printArray(matB,n);
	//(5) Call matMult to multiply the 2 arrays here.
	int **matC = matMult(matA,matB,n);

	printArray(matC,n);



    return 0;
}