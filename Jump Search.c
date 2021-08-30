#include<stdio.h>
#include <math.h>
int jumpSearch(int arr[],int n,int key){
	int jump=sqrt(n);
	while(arr[jump]<key){
		jump=jump+sqrt(n);
	}
	int linearSearchStart=jump-sqrt(n);
	for(int i=linearSearchStart;i<n;i++){
		if (arr[i]==key)
		{
			return i;
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
	if(jumpSearch(arr,n,key)!=-1){
		printf("Index : %d",jumpSearch(arr,n,key));
	}
	if(jumpSearch(arr,n,key)==-1){
		printf("Index : Not found.");
	}
	return 0;
}