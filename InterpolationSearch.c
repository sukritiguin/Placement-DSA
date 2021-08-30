#include <stdio.h>

int interpolationSearch(int arr[],int start,int end,int key){
	int pos;
	if(start<=end && key>=arr[start] && key<=arr[end]){
		pos = start+(((double)(end-start)/(arr[end]-arr[start]))*(key-arr[start]));
		if(arr[pos]==key)
			return pos;
		if(arr[pos]<key){
			interpolationSearch(arr,pos+1,end,key);
		}
		if(arr[pos]>key){
			interpolationSearch(arr,start,pos-1,key);
		}
	}
	return -1;
}

int main(){
	int n;
	printf("Enter the number of elements in array : ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the elements in array : ");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	int key;
	printf("Enter the searched element : ");
	scanf("%d",&key);
	int start=0,end=n-1;
	int index=interpolationSearch(arr,start,end,key);
	if(index!=-1)
		printf("Index : %d",index);
	if(index==-1){
		printf("Index : Not found.");
	}
	return 0;
}