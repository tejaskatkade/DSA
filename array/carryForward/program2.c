// Leaders in Array

#include<stdio.h>

void main(){

	int arr[6]={16,17,3,4,5,2};
	int ans=arr[6-1];
	printf(" %d",ans);
	for(int i=6-1; i>=0; i--){
		if(arr[i]>ans){
			ans = arr[i];
			printf(" %d ",ans);

		}
	}
	printf("\n");
}
