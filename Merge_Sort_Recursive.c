#include <stdio.h>

void mergeSort(int arr[],int low,int high){
	if(low<high){
		int mid = (low+high)/2;
		mergeSort(arr,low,mid);
		mergeSort(arr,mid+1,high);
		merge(arr,low,high,mid);
	}
}

void merge(int arr[],int low,int high,int mid){
	int n1 = mid-low+1;
	int n2 = high-mid;
	int k;
	int L[n1],R[n2];
	for(int i=0;i<n1;i++){
		L[i]=arr[low+i];
	}
	for(int i=0;i<n2;i++){
		R[i]=arr[mid+1+i];
	}
	int i=0,j=0;
	k=low;
	while(i<n1 && j<n2){
		if(L[i]<=R[j]){
			arr[k]=L[i];
			i++;
		}
		if(R[j]<=L[i]){
			arr[k]=R[j];
			j++;
		}
		k++;
	}

	while(i<n1){
		arr[k]=L[i];
		i++;
		k++;
	}
	while(j<n2){
		arr[k]=R[j];
		j++;
		k++;
	}
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
	mergeSort(arr,0,n-1);
	printf("Array after sorting : ");
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
}