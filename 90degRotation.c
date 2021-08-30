#include <stdio.h>

void transpose(int row,int col,int matrix[][col]){
	for (int i = 0; i < col; ++i)
	{
		for(int j=0;j<i;j++){
			int temp=matrix[i][j];
			matrix[i][j]=matrix[j][i];
			matrix[j][i]=temp;
		}
	}
}

void reverseRow(int row,int col,int matrix[][col]){
	for (int i = 0; i < col; ++i)
	{
		for(int j=0;j<col/2;j++){
			int temp=matrix[i][j];
			matrix[i][j]=matrix[i][col-j-1];
			matrix[i][col-j-1]=temp;
		}
	}
}

void display(int row,int col,int arr[][col]){
	for (int i = 0; i < row; ++i)
	{
		for(int j=0;j<col;j++){
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
}

int main(){
	int row,col;
	printf("Enter the number of rows : ");
	scanf("%d",&row);
	printf("Enter the number of columns : ");
	scanf("%d",&col);
	int matrix[row][col];
	printf("Enter the elements of matrix : \n");
	for (int i = 0; i < row; ++i)
	{
		for(int j=0;j<col;j++){
			scanf("%d",&matrix[i][j]);
		}
	}
	printf("The Given matrix : \n");
	for (int i = 0; i < row; ++i)
	{
		for(int j=0;j<col;j++){
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}

	transpose(row,col,matrix);
	reverseRow(row,col,matrix);
	printf("After 90deg rotation, matrix : \n");
	display(row,col,matrix);

	return 0;
}