//1. WAP for the Linked List of malls consisting of its names, numbers of shops & revenue, connect 3 malls in the linked list & print the data.

#include<stdio.h>
#include<stdlib.h>

typedef struct mall{

	char name[20];
	int shops;
	float rev;
	struct mall* next;
}mall;

mall* head = NULL;

void createNode(){
	mall* newNode = (mall*)malloc(sizeof(mall));

	printf("Enter mall name:\n");
	
	int i=0;
        char ch;
	
	while((ch=getchar ())!= '\n'){
		(*newNode).name[i++]=ch;
	}
	printf("Enter the total number of shops\n");
	scanf("%d",&newNode->shops);
 
	printf("Enter the revenue:\n");
	scanf("%f",&newNode->rev);
	getchar();
	
	newNode->next = NULL;

	if(head == NULL)
		head = newNode;
	else{
		mall* temp = head;
		while(temp->next != NULL){
			temp=temp->next;
		}
		temp->next=newNode;
	}
}

void printLL(){

	mall* temp = head;

	while(temp != NULL){
		printf("|%s = ",temp->name);
		printf("%d =",temp->shops);
		printf("%f|",temp->rev);
		temp= temp->next;
	}
}

void main(){
	createNode();
	createNode();
	printLL();
}
