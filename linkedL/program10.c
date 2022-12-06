#include<stdio.h>
#include<stdlib.h>

typedef struct student{
	char mName[20];
	float imdb;
	struct student *next;
}stud;

stud * head = NULL;

void addNode(){
	stud * newNode = (stud*)malloc(sizeof(stud*));
	printf("Enter the string:\n");
	fgets(newNode->mName,20,stdin);
	printf("Enter the rating\n");
	scanf("%f",&newNode->imdb);

	newNode->next = NULL;
	head=newNode;

}

void printLL(){
	stud* temp = head;
	while(temp != NULL){
		puts(temp->mName);
		printf("%f\n",temp->imdb);

		temp=temp->next;
	}
}
void main(){
	addNode();
	printLL();

}
