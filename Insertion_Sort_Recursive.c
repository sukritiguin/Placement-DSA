#include<stdio.h>

void insertionSort(int arr[],int n){
	if(n<=1)
		return;
	insertionSort(arr,n-1);
	int last = arr[n-1];
	int j = n-2;
	while(j>=0 && arr[j]>last){
		arr[j+1]=arr[j];
		j--;
	}
	arr[j+1]=last;
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
	insertionSort(arr,n);
	printf("Array after sorting : ");
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
}