#include<stdio.h>
#include<stdlib.h>

typedef struct Employee{
	char name[20];
	int id;
	struct Employee *next;
}Emp;

Emp * head = NULL;

Emp* createNode(){
	Emp* newNode = (Emp*)malloc(sizeof(Emp));
	getchar();
	int i=0;
	char ch;
	
	printf("Enter Name:\n");
	while((ch = getchar()) != '\n'){
		(*newNode).name[i]=ch;
		i++;
	}
	printf("Enter id:\n");
	scanf("%d",&newNode->id);

	return newNode;
}
void addNode(){

	Emp* newNode = createNode();

	if(head == NULL)
		head = newNode;
	else{
		Emp* temp = head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next=newNode;
	}
}

void countNode(){
	int count = 0;
	Emp* temp = head;
	while(temp!=NULL){
		count++;
		temp=temp->next;
	}
	printf("Total nodes are %d\n",count);

}

void printLL(){

	Emp* temp =head;

	while(temp != NULL){
		printf("|%s =>",temp->name);
		printf(" %d|",temp->id);
		temp=temp->next;		
	}

}
void addFirst(){
	Emp* newNode = createNode();

	newNode->next = head;
	head = newNode;

}

void addAtPos(){
	int pos;

	printf("At which position do you want to add a Node:\n");
	scanf("%d",&pos);
	
	Emp* newNode = createNode();
	Emp*temp = head;

	while(pos-2){
		temp=temp->next;
		pos--;
	}
	newNode->next = temp->next;
	temp->next = newNode;

}


void main(){
	int num;
	printf("How many nodes do you want:\n");
	scanf("%d",&num);
	for(int i=0; i<num; i++){
		addNode();
	}
	printf("Enter node to add at first:\n");
	addFirst();
	
	printLL();

	countNode();

	addAtPos();

	printLL();

	countNode();
		
}
