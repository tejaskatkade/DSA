//Print all the subarray

#include<stdio.h>

void main(){

	int arr[]={4,2,1,3};
	int N=4;
	int var=0;
	for(int i=0; i<N; i++){
		for(int j=i; j<N; j++){
			int sum =0;
			for(int k=i; k<=j; k++){
				printf("%d",arr[k]);
				sum= sum+arr[k];
			}
			printf("\n");
			printf("sum = %d",sum);
			printf("\n");
		}

	}
}
