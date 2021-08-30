#include <stdio.h>

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

int largest(int arr[],int n, int position){
	return arr[n-position];
}

int smallest(int arr[],int n, int position){
	return arr[0+position-1];
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
	selectionSort(arr,n);
	int k_smallest,k_largest;
	printf("Enter the K-th smallest postion : ");
	scanf("%d",&k_smallest);
	printf("%d-th smallest element : %d\n",k_smallest,smallest(arr,n,k_smallest));
	printf("Enter the K-th largest postion : ");
	scanf("%d",&k_largest);
	printf("%d-th largest element : %d",k_largest,largest(arr,n,k_largest));


	return 0;
}