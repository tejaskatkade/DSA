//5. 

#include<stdio.h>
#include<stdlib.h>

typedef struct demo{

	int data;
	struct demo *next;
}demo;

demo* head = NULL;

void addNode(){
	demo* newNode = (demo*)malloc(sizeof(demo));

	printf("Enter data\n");
	scanf("%d",&newNode->data);

	if(head == NULL){
		head = newNode;
	}else{
		demo* temp = head;
		while(temp->next != NULL){
		
			temp= temp->next;
		}
		temp->next = newNode;
	}

}
void countnodes(){
	demo* temp = head;
	int count=0;
	while(temp!=NULL){
		count++;
		temp=temp->next;
	}
	printf("\nTotal nodes %d\n",count);
}
void addData(){
	int add=0;
	demo* temp = head;
	while(temp!=NULL){
		add += temp->data;
		temp= temp->next;
	}
	printf("Addition of data is %d\n",add);
}
void printLL(){
	demo* temp = head;
	while(temp != NULL){
		
		printf("| %d |",temp->data);
		temp=temp->next;
	}
}


void main(){
	int num;
	printf("How many nodes do you want:\n");
	scanf("%d",&num);
	for(int i=0; i< num; i++){
		addNode();
	}
	addData();
	printLL();
	countnodes();
}
