#include<stdio.h>
void fun(int x){
	printf("Hello \n");
	if(x != 1){
		fun(--x);
	}
	printf("Bye\n");
}
void main(){
	int num = 5;
	fun(num);
}

//OUTPUT =>

//Hello
//Hello
//Hello
//Hello
//Hello
//Bye
//Bye
//Bye
//Bye
//Bye
