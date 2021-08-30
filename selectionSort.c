#include<stdio.h>

void selectionSort(int arr[],int n){
	for(int i=0;i<n-1;i++){
		for (int j = i+1; j < n; j++)
		{
			if(arr[j]<arr[i]){
				int temp=arr[i];
			    arr[i]=arr[j];
			    arr[j]=temp;
			}
		}
	}
}

int main(){
	int n;
	printf("Enter the size of array : ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the elements of array : ");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	selectionSort(arr,n);
	printf("Sorted array : ");
	for (int i = 0; i < n; ++i)
	{
		printf("%d ",arr[i]);
	}
}