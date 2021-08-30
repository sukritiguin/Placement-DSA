#include <stdio.h>

int reverseArray(int arr[],int n){
	int start=0,end=n-1;
	while(start<end){
		int temp=arr[start];
		arr[start]=arr[end];
		arr[end]=temp;
		start++;
		end--;
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
	reverseArray(arr,n);
	printf("Reverse Array : ");
	display(arr,n);

	return 0;
}