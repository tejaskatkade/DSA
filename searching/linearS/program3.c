//SECOND LAST OCCURANCE


#include<stdio.h>

int secLastOccurance(int arr[], int sz, int ele){

	int store = -1;
	int seclast = -1;
	for(int i=0; i<sz; i++){
		if(arr[i] == ele){
			seclast = store;
			store = i;
		}
	}
	return seclast;
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
	printf("Enter the element to find its second last occurance\n");
	scanf("%d",&ele);
	int index = secLastOccurance(arr,sz,ele);
	if(index == -1){
		printf("Not found once or twice\n");	
	}else{
		printf("The second last occurance of %d is %d\n",ele, index);
	}
}
