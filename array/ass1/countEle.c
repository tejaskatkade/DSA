// Count element - having atleast one bigger element

#include<stdio.h>

//Array changes
/*
void swap(int *a, int *b){
	int temp=*a; 
	*a=*b;
	*b= temp;
}
int countEle(int arr[],int size){
	
	int count=0;
	int same=0;
	for(int i=0; i<size-1; i++){
		if(arr[i]>arr[i+1]){
			swap(&arr[i],&arr[i+1]);
		}
	}
	for(int i=0; i<size-1; i++){
		if(arr[i]== arr[size-1])
			same++;
	}

	count = size-same-1;
	return count;

}
*/

int countEle(int arr[], int size){
	int count=0;
	int same=0;
	int store = arr[0];
	for(int i=1; i<size; i++){
		if(store<arr[i]){
			store == arr[i];
			same =0;
		}
		if(store == arr[i]){
			same++;
		}
	}
	count=size-same-1;

}
void main(){
	int arr[10]={1,3,-2,-7,5,1,6,6,4,1};

	int val = countEle(arr,10);

	printf("count = %d\n",val);
}
