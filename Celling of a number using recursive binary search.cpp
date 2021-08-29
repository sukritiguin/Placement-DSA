#include<stdio.h>
#include<stdlib.h>

void search_celling(int arr[],int arr_size,int target,int start,int end){
    if(start<=end){
        int mid = (start+end)/2;
        if(arr[mid]==target){//if targer element is qual to arr[mid] then arr[mid] will be celling element
            printf("The celling element is : %d\n",arr[mid]);
            return;
        }
        else if(target<arr[mid])
            search_celling(arr,arr_size,target,start,mid-1);
        else if(target>arr[mid])
            search_celling(arr,arr_size,target,mid+1,end);
    }
    else if(start>=arr_size){//if we search such a elment that does not exit in array then target is out of bound.
            printf("No element is found.\n");
            return;
        }
    else if(start>end){//start>end means : next of mid element then return
        // 1st : go untill start==end then mid=start=end but celling is less or greater than arr[mid]
        // 2nd : in such case end will be decremented or start will be incremented
        // 3rd : then upper element start will be > than end and srr[start] will be answer then return
        printf("The celling element is : %d\n",arr[start]);
        return;
    }
}


int main(){
    int array_size;
    printf("Enter the array size : ");
    scanf("%d",&array_size);
    int arr[array_size];
    printf("Enter array elements : ");
    for(int i=0;i<array_size;i++){
        scanf("%d",&arr[i]);
    }
    int target;
    printf("Enter the target element : ");
    scanf("%d",&target);
    search_celling(arr,array_size,target,0,array_size-1);
    return 0;
}
