#include <stdio.h>

void spiralPrint(int row,int col,int matrix[][col]){
	int l=0,k=0,m=row,n=col;
	while(k<m && l<n){
		for (int i = l; i < n; ++i)
		{
			printf("%d ",matrix[k][i]);
		}
		k++;
		for (int i = k; i < m; ++i)
		{
			printf("%d ",matrix[i][n-1]);
		}
		n--;
		if(k<m){
			for (int i = n-1; i >= l; i--)
			{
				printf("%d ",matrix[m-1][i]);
			}
			m--;
		}
		if(l<n){
			for (int i = m-1; i >= k; i--)
			{
				printf("%d ",matrix[i][l]);
			}
			l++;
		}
	}
}

int main(){
	int row,col;
	printf("Enter the number of rows : ");
	scanf("%d",&row);
	printf("Enter the number of columns : ");
	scanf("%d",&col);
	int matrix[row][col];
	printf("Enter the elements of matrix : ");
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
	printf("Spiral printf of the matrix : ");
	spiralPrint(row,col,matrix);

	return 0;
}