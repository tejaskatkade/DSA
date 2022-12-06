#include<stdio.h>
#include<stdlib.h>

int* fun(){
	int *arr;
	int n = 5;
	arr = (int *)malloc(n*sizeof(int));
	printf("Enter array element:\n");
	for(int i=0; i<5; i++){
		scanf("%d",&arr[i]);
	}
	return arr;
}

void main(){
	int *ptr;
        ptr=fun();
	printf("The array elements are:\n")
	for(int i=0; i< 5; i++){
		printf("%d\n",ptr[i]);
	}
}
