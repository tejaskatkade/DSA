//VOID POINTERS

#include<stdio.h>
void main(){
	int x =10;
	char ch='a';
	float f=12.3;

	void *arr[]={&x,&ch,&f};

	printf("%p\n",arr[0]);
	printf("%p\n",arr[1]);
	printf("%p\n",arr[2]);


	printf("%p\n",(int *)(arr[0]));
	
	printf("%d\n",*(int *)(arr[0]));
	printf("%c\n",*(char *)(arr[1]));
	printf("%f\n",*(float *)(arr[2]));



}
