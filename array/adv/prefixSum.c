//Construct the prefix sum of array in the given array itself
//Return an array of integers denotinh the prefix sum of th given arrayd.

#include<stdio.h>

void prefixSum(int arr[],int N){
	for(int i=1; i<N; i++){
		arr[i]=arr[i]+arr[i-1];
	}
}
void main(){
	int arr[7]={3,5,6,-6,5,1,3};
	int N =7;
	for(int i=0; i<N;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");

	prefixSum(arr,N);
	for(int i=0;i<N; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");

}
