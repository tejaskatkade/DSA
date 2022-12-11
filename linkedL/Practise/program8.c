//9.  

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
	newNode->next = NULL;

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

void primeNode(){

	int flag;
	demo*temp = head;
	while(temp != NULL){
		int num = temp->data;
		if(num == 2){
			flag =2;
		}else{
			
			for(int i=1; i<=num; i++){
				flag =0;
				if(num/i == 0){
					flag++;
				}
			}

			if(flag ==2){
				printf("\nPrime data is %d\n",num);
			}
			
		}

		temp=temp->next;
	}
}
void printLL(){
	demo* temp = head;
	while(temp != NULL){
		
		printf("| %d |",temp->data);
		temp=temp->next;
	}
	printf("\n");
}


void main(){
	int num;
	printf("How many nodes do you want:\n");
	scanf("%d",&num);
	for(int i=0; i< num; i++){
		addNode();
	}

	printLL();
	primeNode();
	countnodes();
}
