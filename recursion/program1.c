#include<stdio.h>
int num = 0;
void fun(){
	//static int num = 0;
	printf("%d\n",++num);
	fun();
}
void main(){
	fun();
}
