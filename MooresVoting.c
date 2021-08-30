#include<stdio.h>
#define bool int

int findCandidate(int*,int);
bool isMejority(int*,int,int);

void printMejority(int arr[],int n){
	int cand=findCandidate(arr,n);
	if(isMejority(arr,n,cand)){
		printf("Mejority element : %d",cand);
	}
	else
		printf("Mejority element : Not found");
}

int findCandidate(int arr[],int n){
	int majIndex=0,count=1;
	for(int i=1;i<n;i++){
		if(arr[majIndex]==arr[i]){
			count++;
		}
		else{
			count--;
		}
		if(count==0){
			majIndex=i;
			count=1;
		}
	}
	return arr[majIndex];
}

bool isMejority(int arr[],int n,int cand){
	int count=0;
	for (int i = 0; i < n; ++i)
	{
		if (arr[i]==cand)
		{
			count++;
		}
	}
	if(count>(n/2)){
		return 1;
	}
	else
		return 0;
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
	printMejority(arr,n);
	return 0;
}