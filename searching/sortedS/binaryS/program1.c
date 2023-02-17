#include<stdio.h>
int binaryS(int arr[],int sz, int key){
	int start = 0; int end = sz;
	while(start <= end){
		int mid = (start + end)/2;

		if(arr[mid] == key){
			return mid;
		}
		if(arr[mid] > key){
			end = mid-1;	
		}
		if(arr[mid] < key){
			start = mid+1;
		}
			
	}
	return -1;
}

void main(){
	int arr[14]={1,3,6,7,8,9,12,23,54,65,67,89,97,122};
	int index=binaryS(arr, 14, 7);
	printf("Element found at %d\n",index);
}
