//insertion
#include<stdio.h>
void insertion(int arr[],int size){
	for(int i=0; i<size; i++){
		int store= arr[i];
		for(int j=i-1; j>=0; j--){
			if(arr[i]<arr[j]){
				arr[j]=store;
			}
			if(j=0)
				arr[j]=store;
		}
	}

}

void main(){
	int arr[]={1,4,5,2,3};

	insertion(arr,5);

	for(int i=0; i<5; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
