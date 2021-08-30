#include <stdio.h>
#include <stdlib.h>

int temp(int arr[],int n,int tempArray[],int number_rotation){
	for (int i = 0; i < number_rotation; ++i)
	{
		tempArray[i]=arr[i];
	}
	return tempArray[number_rotation];
}

int rotatedArray(int arr[],int n,int tempArray[],int number_rotation){
	for (int i = number_rotation; i < n; ++i)
	{
		arr[i-number_rotation]=arr[i];
	}
	for (int i = 0; i < number_rotation; ++i)
	{
		arr[n-number_rotation+i]=tempArray[i];
	}
	return arr[n];
}

void display(int arr[],int n){
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
}


int main(){
	int n;
	printf("Enter the number of elements in array : ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the elements : ");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	int number_rotation;
	printf("Enter the number of rotation : ");
	scanf("%d",&number_rotation);
	int tempArray[number_rotation];
	printf("Main Array : ");
	display(arr,n);
	tempArray[number_rotation]=temp(arr,n,tempArray,number_rotation);
	rotatedArray(arr,n,tempArray,number_rotation);
	printf("\nAfter rotation, Array : ");
	display(arr,n);

	return 0;
}