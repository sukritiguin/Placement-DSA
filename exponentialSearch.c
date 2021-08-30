#include <stdio.h>

int min(int i,int n){
	if(i<n)
		return i;
	else if(n<i)
		return n;
	else
		return i;
}

int binarySearch(int arr[],int start,int end,int key){
	while(end>=start){
		int middle=(start+(end-1))/2;
		if(arr[middle]==key)
			return middle;
		if(arr[middle]>key)
			return binarySearch(arr,start,middle-1,key);
		if(arr[middle]<key)
			return binarySearch(arr,middle+1,end,key);
	}
	return -1;
}

int exponentialSearch(int arr[],int n,int key){
	if (arr[0]==key)
	{
		return 0;
	}
	int i=1;
	while(i<n && arr[i]<key){
		i=i*2;
	}
	return binarySearch(arr,i/2,min(i,n),key);
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
	int index=exponentialSearch(arr,n,key);
	if(index!=-1)
		printf("Index : %d",index);
	if(index==-1){
		printf("Index : Not found.");
	}

	return 0;
}