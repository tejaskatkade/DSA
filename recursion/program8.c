#include<stdio.h>
int fun(int N){
	if(N<=1){
		return 1;
	}
	int x = fun(N-1);
	int y = fun(N-2);

	printf("x=%d\n",x);
	printf("y=%d\n",y);

	printf("\n");

}

void main(){
	int N = 4;
	fun(4);

}
