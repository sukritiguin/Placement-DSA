#include<stdio.h>
#include<limits.h>

int maxSum(int arr[],int n){
	int msf=INT_MIN,meh=0;
	for (int i = 0; i < n; ++i)
	{
		meh=meh+arr[i];
		if(meh<arr[i]){
			meh=arr[i];
		}
		if(msf<meh){
			msf=meh;
		}
	}
	return msf;
}

int main(){
	int n;
	printf("Enter the number of elements in array : ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the elements of array : ");
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&arr[i]);
	}
	printf("Largest Sum of contiguous sub-array : %d",maxSum(arr,n));

	return 0;
}