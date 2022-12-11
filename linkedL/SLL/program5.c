#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct movie{

	int tic;
	char mName[20];
	float price;
	struct movie *next;
}mv;

void printData(mv *ptr){

	printf("%d\n",ptr->tic);
	printf("%s\n",ptr->mName);
	printf("%f\n",ptr->price);
	printf("%p\n",ptr->next);
	
	printf("\n");
}
void main(){

	mv* ptr1=(mv*)malloc(sizeof(mv));
	mv* ptr2=(mv*)malloc(sizeof(mv));
	mv* ptr3=(mv*)malloc(sizeof(mv));

	ptr1->tic=5;
	strcpy(ptr1->mName,"Kantara");
	ptr1->price=500;
	ptr1->next=ptr2;
	
	ptr2->tic=3;
	strcpy(ptr2->mName,"Drishyam 2");
	ptr2->price=450;
	ptr2->next=ptr3;
	
	ptr3->tic=7;
	strcpy(ptr3->mName,"Vikram Veda");
	ptr3->price=1050;
	ptr3->next=NULL;

	printData(ptr1);
	printData(ptr2);
	printData(ptr3);
}
