//take two array of same size
//sort both array and save it in the third array

#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int arr[],int size){
	for(int i=0; i<size; i++){
		for(int j=i+1; j<size; j++){
			if(arr[i]>arr[j]){
				int temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}

}
int* mergeSort(int arr1[],int arr2[],int size1,int size2){
	int j = 0;
	int k = 0;

	int* arr3=(int *)malloc((size1+size2)*sizeof(int));
	for(int i=0; i<size1+size2; i++){
		if(j == size1){
			arr3[i]=arr2[k];
		}else if(k == size2){
			arr3[i]=arr1[j];
		}else{
			if(arr1[j]>arr2[k]){
				arr3[i]=arr2[k];
				k++;
			}else{
				arr3[i]=arr1[j];
				j++;
			}
		}
	}
	return arr3;
}

void main(){
	int arr1[4]={6,5,3,7};
	int arr2[5]={2,5,10,4,6};

	bubbleSort(arr1,4);
	bubbleSort(arr2,5);
	printf("Sorted array\n");
	printf("arr1\n");
	for(int i=0; i<4; i++){
	
		printf("%d ",arr1[i]);

	}
	printf("\n");
	printf("arr2\n");
	for(int i=0; i<5; i++){
	
		printf("%d ",arr2[i]);

	}
	printf("\n");

	int * arr3 = mergeSort(arr1,arr2,4,5);

	printf("arr3\n");
	for(int i=0; i<9; i++){
	
		printf("%d ",arr3[i]);

	}

}
