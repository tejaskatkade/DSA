#include<stdio.h>

int isFound(int arr[],int sz, int ele){
	for(int i=0; i<sz; i++){
		if(arr[i] == ele)
			return i;
	}
	return -1;
}

void main(){
	int sz;
	int ele;
	printf("Enter the size of an array\n");
	scanf("%d",&sz);
	int arr[sz];
	printf("Enter the elements of an array\n");
	
	for(int i=0; i< sz; i++){
		scanf("%d",&arr[i]);
	}
	printf("Enter the element to find in an array\n");
	scanf("%d",&ele);

	int val=isFound(arr,sz,ele);
	if(val == -1)
		printf("Element not found\n");
	else	
		printf("Element Found at index %d\n",val);
	
}
