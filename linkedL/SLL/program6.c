#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {

	int data;
	struct Node *next;
};

void main(){

	struct Node *head = NULL;

	//First node
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

	newNode->data = 10;
	newNode->next = NULL;

	//connecting head ...
	//Connecting 1st node
	head = newNode;

	//Second node
	newNode = (struct Node*)malloc(sizeof(struct Node));

	newNode->data = 20;
	newNode->next = NULL;

	//connecting 2nd Node
	head->next = newNode;

	//Third node
	newNode = (struct Node*)malloc(sizeof(struct Node));

	newNode->data=30;
	newNode->next=NULL;

	//connecting third Node
	head->next->next = newNode;

	struct Node * temp = head;
	
	while(temp!= NULL){
		printf("%d\n",temp->data);
		temp=temp->next;
	}
}
