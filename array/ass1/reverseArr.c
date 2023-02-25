#include<stdio.h>

void reverseArray(int arr[],int N){
	int i = 0;
	int j = N-1;
	while(i<j){
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;

		i++;
		j--;
	}
}
void main(){
	int arr[7]={3,6,3,6,3,6,7};
	int N=7;
	reverseArray(arr,N);
	for(int i=0; i<N; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
