//Rotate arr B times towards right

#include<stdio.h>

void rotateArr(int arr[], int N, int B){
	for(int i=0; i<B; i++){
	
		int store = arr[N-1];
		int j=N-1;
		while(j > 0){
			arr[j]=arr[j-1];
			j--;
		}
		arr[0]=store;
	}

}
void main(){
	int arr[5]={2,3,1,4,5};
	int N=5;
	int B;
	printf("Enter the no. of rotation\n");
	scanf("%d",&B);
	rotateArr(arr,N,B);
	for(int i=0; i<N; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
