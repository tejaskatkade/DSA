// Range sum query

#include<stdio.h>

int sum(int S[], int a, int b){
	if(a == 0){
		return S[b];
	}else{
		return S[b]-S[a-1];
	}
}

void main(){
	//1-D array
	int A[6]={2,1,8,3,9,6};
	
	//2-D array of queries
	int B[4][2]={0,3,3,5,1,3,2,4};

	//array for outpur
	int C[4];

	//prefix sum
	int sz=6;
	int S[sz];
	S[0]=A[0];
	
	for(int i=1; i<6; i++){
		S[i]=S[i-1]+A[i];
	}

/*	for(int i=0; i<6; i++){
		printf("%d",S[i]);
	}
	printf("\n");
*/	
	//Passing queries to the function
	for(int i=0; i<4; i++){
		int val=sum(S,B[i][0],B[i][1]);
		C[i]=val;	
	}

	//printing the output array
	for(int i=0; i<4; i++){
		printf(" %d ",C[i]);
	}
	
	
	printf("\n");
}
