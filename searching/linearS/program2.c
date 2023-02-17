// LAST OCCURANCE

#include<stdio.h>

int lastOccurance(int arr[], int sz, int ele){

	int store = -1;
	for(int i=0; i<sz; i++){
		if(arr[i] == ele)
			store = i;
	}
	return store;
}

void main(){
	int sz;
	int ele;
	printf("Enter the size of an array\n");
	scanf("%d",&sz);
	int arr[sz];
	printf("Enter the array elements\n");
	for(int i=0; i<sz; i++){
		scanf("%d",&arr[i]);
	}
	printf("Enter the element to find its last occurance\n");
	scanf("%d",&ele);
	int index = lastOccurance(arr,sz,ele);
	if(index == -1){
		printf("Not found\n");	
	}else{
		printf("The last occurance of %d is %d\n",ele, index);
	}
}
