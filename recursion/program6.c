//FACTORIAL 

#include<stdio.h>

int factorial(int num){
	static int fact = 1;
	fact = fact * num;
	if(num>1){
		factorial(--num);
	//	printf("%d\n",num);
	}
	return fact;
}
void main(){
	int num;
	printf("Enter the number to find factorial\n");
	scanf("%d",&num);
	int fact = factorial(num);
	printf("Factorial of %d is %d\n",num,fact);
}
