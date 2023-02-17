//take two array of same size
//add 1st ele of both array and save it in the third array
//

#include<stdio.h>
void main(){
	int arr1[4]={6,5,3,7};
	int arr2[4]={2,10,4,6};

	int arr3[4];

	for(int i=0; i<4; i++){
		arr3[i]=arr1[i]+arr2[i];
	}

	printf("Third array is\n");
	for(int i=0; i<4; i++){
	
		printf("%d\n",arr3[i]);
	}
}
