//K th smallest ele

#include<stdio.h>

int merge(int arr[], int start, int mid , int end, int B){
	int ele1=mid-start+1;
	int ele2=end-mid;

	int arr1[ele1];
	int arr2[ele2];

	for(int i=0; i<ele1; i++){
		arr1[i]=arr[start+i];
	}
	for(int j=0; j<ele2; j++){
		arr2[j]=arr[mid+1+j];
	}

	int itr1=0, itr2=0, itr3=start;

	while(itr1 < ele1 && itr2 <ele2){
		if(arr1[itr1] < arr2[itr2]){
			arr[itr3] = arr1[itr1];
			itr1++;
		}else{
			arr[itr3]=arr2[itr2];
			itr2++;
		}
		if(itr3 == B-1){
			return arr[itr3];
		}
		itr3++;
	}

	while(itr1 < ele1){
		arr[itr3]=arr1[itr1];
		
		if(itr3 == B-1){
			return arr[itr3];
		}
		itr3++;
		itr1++;

	}
	while(itr2 < ele2){
		arr[itr3]=arr2[itr2];
		if(itr3 == B){
			return arr[itr3];
		}
		itr3++;
		itr2++;

	}

}
int mergeSort(int arr[],int start, int end,int B){
	int num;
	if(start<end){
		int mid = (start+end)/2;

		mergeSort(arr,start,mid,B);
		mergeSort(arr,mid+1,end,B);
		num = merge(arr,start,mid,end,B);
	}
	return num;
}

void main(){
	
	int arr[9]={9,-3,-1,8,6,4,11,5,2};
	int num = mergeSort(arr,0,8,7);
	
	printf("%d\n",num);
	for(int i=0; i<9; i++){
		printf("%d ",arr[i]);

	 }
	printf("\n");
}
