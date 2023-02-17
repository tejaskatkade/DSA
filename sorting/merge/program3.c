// Draw the diagram

#include<stdio.h>

void recfun(int arr[],int size){
	int start = 0;
	int end = size-1;

	if(start<end){
		int mid = (start+end)/2;
		printf("%d",mid);
		recfun(arr,mid+1);
	}
	printf("Hello\n");
}
void main(){
	int arr[]={7,2,4,2,9,6,5,3};
	int size = sizeof(arr)/sizeof(int);

	recfun(arr,size);
}
