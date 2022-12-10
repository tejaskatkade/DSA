//WAP for the LinkedList of states in India consisting of its name. Population, Budget & Literacy connect 4 states in the linkedlist & print their data;

#include<stdio.h>
#include<stdlib.h>

typedef struct state{
	char name[20];
	int pop;
	float bud;
	float lit;
	struct state* next;
}stat;
stat *head = NULL;

void createNodes(){
	stat* newNode = (stat*)malloc(sizeof(stat));
	getchar();
	printf("Enter state name\n");
	int i=0;
	char ch;
	while((ch = getchar())!= '\n'){
		(*newNode).name[i++]=ch;
	}
	printf("Enter population:\n");
	scanf("%d",&newNode->pop);

	printf("Enter Budget:\n");
	scanf("%f",&newNode->bud);

	printf("Enter Literacy:\n");
	scanf("%f",&newNode->lit);
	
	newNode->next = NULL;
	
	if(head == NULL)
		head = newNode;
	else{
		stat* temp = head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = newNode;
	}
	
}
void printLL(){

	stat* temp = head;
	while(temp != NULL){
		
		printf("|%s -",temp->name);
		printf("%d -",temp->pop);
		printf("%f -",temp->bud);
		printf("%f|",temp->lit);
		temp= temp->next;
	}
}
void main(){
	int num;
	printf("How many nodes do you want:\n");
	scanf("%d",&num);
	for(int i=0; i<num; i++){
		createNodes();
	}
	printLL();

}
