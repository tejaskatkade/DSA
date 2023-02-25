// Reverse the array in given Range

#include<stdio.h>

void reverse(int arr[],int size,int start, int end){
	
	for(int i=0; i<size; i++){
		printf("%d",arr[i]);
	}
	printf("\n");

	int i=start-1;
	int j=end-1;

	while(i<j){
		int temp = arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
		i++;
		j--;

	}


	for(int i=0; i<size; i++){
		printf("%d",arr[i]);
	}
	printf("\n");

	
}
void main(){

	int arr[7]={ 2,3,4,6,5,1,7};
	int start, end;


	//int size = sizeof(arr)/sizeof(arr[0]);

	printf("Enter the start and end value\n");
	scanf("%d %d",&start,&end);
	reverse(arr,7,start,end);
}

