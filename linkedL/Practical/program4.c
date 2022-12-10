//2. WAP to count the number of festivals

#include<stdio.h>
#include<stdlib.h>

typedef struct festival{

	char name[20];
	int days;
	struct festival *next;
}fest;

fest* head = NULL;

void addNode(){
	fest* newNode = (fest*)malloc(sizeof(fest));
	
	
	int i=0;
	char ch;

	printf("Enter the name of festival\n");
	
	while((ch=getchar())!='\n'){
		(*newNode).name[i]=ch;
		i++;
	}
	printf("Enter days\n");
	scanf("%d",&newNode->days);
	getchar();

	if(head == NULL){
		head = newNode;
	}else{
		fest* temp = head;
		while(temp->next != NULL){
		
			temp= temp->next;
		}
		temp->next = newNode;
	}

}
void countfest(){
	fest* temp = head;
	int count=0;
	while(temp!=NULL){
		count++;
		temp=temp->next;
	}
	printf("%d festivals are in LinkedList\n",count);
}
void printLL(){
	fest* temp = head;
	while(temp != NULL){
		printf("%s = ",temp->name);
		printf("%d\n",temp->days);
		temp=temp->next;
	}
}


void main(){
	addNode();
	addNode();
	printLL();
	countfest();
}
