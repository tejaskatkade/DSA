//Returning array as pointer

#include<stdio.h>
#include<stdlib.h>

int* fun(){
	int *arr;
	int n = 5;
	arr = (int *)malloc(n*sizeof(int));
	arr[0]=1;
	arr[1]=2;
	arr[2]=4;
	arr[3]=5;
	arr[4]=6;
	return arr;
}

void main(){
	int *ptr;
        ptr=fun();
	for(int i=0; i< 5; i++){
		printf("%d\n",ptr[i]);
	}
}
