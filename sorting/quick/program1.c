//Quick sort

#include<stdio.h>

void swap(int *a, int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}

int partition(int arr[],int start,int end){
	int pivot = arr[end];
	int itr = start-1;

	for(int i=start; i<end; i++){
		
		if(arr[i]<pivot){
			itr++;
			swap(&arr[i],&arr[itr]);
		}
	}
	swap(&arr[itr+1],&arr[end]);
	return itr+1;
}

void quickSort(int arr[],int start, int end){
	if(start<end){
		
		int position = partition(arr,start,end);
		quickSort(arr,start,position-1);
		quickSort(arr,position+1,end);
	}



}

void main(){

	int arr[7]={3,5,7,4,6,8,9};
	int start = 0;
	int end =6;
	quickSort(arr,start,end);

	for(int i=0; i<7; i++){
		printf("%d\n",arr[i]);
	}
	printf("\n");
}
