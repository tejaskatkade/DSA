// Printing number from 10 to 1

#include<stdio.h>
void fun(int num){
	printf("%d\n",num);
	if(num>1){
		fun(--num);
	}
}

void main(){
	printf("Enter the number\n");
	int num;
	scanf("%d",&num);
	fun(num);
}
