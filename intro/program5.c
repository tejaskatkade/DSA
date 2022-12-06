#include<stdio.h>
#include<stdlib.h>

void main()
{
	int *ptr = (int *)malloc(sizeof(int));

	*ptr = 50;

	printf("%d\n",*ptr);

}
