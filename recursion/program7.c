//Array 

#include<stdio.h>
void printArray(int arr[],int size){
	static int i =0;
	printf("%d\n",arr[i]);
	if(i < size-1){
		i++;
		printArray(arr,size);		
	}
}
void main(){
	printf("Enter the size of an array\n");
	int size;
	scanf("%d",&size);
	int arr[size];
	printf("Enter the array elements\n");
	for(int i=0; i<size; i++){
		scanf("%d",&arr[i]);
	}
	printArray(arr,size);
}
