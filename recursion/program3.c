// Printing addition of numbers from 10 to 1

#include<stdio.h>
void fun(int num){
	static int sum=0;
	sum = sum + num;
	if(num>1){
	
		fun(--num);
	}else{
		printf("Sum is %d\n",sum);
	}
}

void main(){
	printf("Enter the number\n");
	int num;
	scanf("%d",&num);
	fun(num);
}
