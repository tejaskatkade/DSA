//ARRAY 

#include <stdio.h>
void main(){
	int sz;
	printf("Enter the size of an array\n");
	scanf("%d",&sz);

	int arr[sz];

	printf("Enter the array elements\n");
	
	for(int i =0; i< sz; i++){
		scanf("%d",&arr[i]);
	}
	
	printf("The array elements are\n");
	for(int i =0; i< sz; i++){
		printf("%d",arr[i]);
	}
	
}
