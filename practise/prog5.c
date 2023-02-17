// pointer to an array

#include<stdio.h>

void fun1(int *arr,int sz){
	printf("%p\n",arr);

}

void fun2(int (*ptr)[7]){
	printf("%p\n",ptr);


}
void main(){
	int arr[7]={1,2,3,4,5,6,7};
	fun1(arr,7);
	fun2(&arr);

}
