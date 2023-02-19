//Good Pair  

#include<stdio.h>

int goodPair(int arr[],int size, int B){
	
	for(int i=0; i<size; i++){
		for(int j=i+1; j<size; j++){
			if(arr[i]+arr[j] == B){
				return 1;
			}
		}
	}
	return 0;
}
void main(){
	int arr[10]={1,3,-2,-7,5,1,6,6,4,1};

	int B;
	printf("Enter the value of B\n");
	scanf("%d",&B);
	int val = goodPair(arr,10,B);
	printf("%d\n",val);
}
