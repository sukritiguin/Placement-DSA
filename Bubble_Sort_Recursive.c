#include<stdio.h>

void bubbleSort(int arr[],int n){
	if(n==1)
		return;
	for(int i=0;i<n-1;i++){
		if(arr[i]>arr[i+1]){
			int temp = arr[i];
			arr[i] = arr[i+1];
			arr[i+1] = temp;
		}
	}
	bubbleSort(arr,n-1);
}

int main(){
	int n;
	printf("Array size : ");
	scanf("%d",&n);
	int arr[n];
	printf("Ente the elemens : ");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	bubbleSort(arr,n);
	printf("Array after sorting : ");
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
}