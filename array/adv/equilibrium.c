// You are given an array of A of size N
// Find equilibrium index
//Equilibrium index of an array is an index such that the sum of elements at lower indexes are tho the sum of elements at higher indexes
//
//

#include<stdio.h>

int equilibriumIndex(int A[], int N){
	int arr[N];
	arr[0]=A[0];
	for(int i=1; i<N; i++){
		arr[i]=arr[i-1]+A[i];
	}

	

	for(int i=0; i<N; i++){
		if(i == 0){
			if(arr[N-1]-arr[i] == 0){
				return i;
			}
		}else if(i == N-1){
			if(arr[N-1-1] == 0){
				return i;
			}
		}else{
			if(arr[i-1] == arr[N-1]-arr[i]){
				return i;
			}
		}
	}
	return -1;
}
void main(){
	int A[3]={1,2,3};
	int N=3;

	int index = equilibriumIndex(A,N);

	printf("Equilibrium index is = %d\n", index);
}
