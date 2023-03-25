// Even numbers in a range

#include<stdio.h>

int count(int A[],int a, int b){
	int cnt=0;
	for(int i=a; i<=b; i++){
		if(A[i]%2 == 0){
			cnt++;
		}
	}
	return cnt;
}
void main(){
	int A[6]={2,1,8,3,9,6};
	
	int B[4][2]={0,3,3,5,1,3,2,4};

	int C[4];

	for(int i=0; i<4; i++){
		int val=count(A,B[i][0],B[i][1]);
		C[i]=val;	
	}
	for(int i=0; i<4; i++){
		printf(" %d ",C[i]);
	}
	printf("\n");
}
