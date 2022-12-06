#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct company{
	char cName[20];
	int empCount;
	float revenue;

};

void main(){
	struct company *cptr = (struct company *)malloc(sizeof (struct company));

	strcpy((*cptr).cName,"Microsoft");
	(*cptr).empCount = 150000;
	(*cptr).revenue = 50;

	printf("%s\n",(*cptr).cName);
	printf("%d\n",(*cptr).empCount);
	printf("%f\n",(*cptr).revenue);	
}
