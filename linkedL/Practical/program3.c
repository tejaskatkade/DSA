//2. Linked list for festivals

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
void printLL(){
	fest* temp = head;
	while(temp != NULL){
		printf("%s = ",temp->name);
		printf("%d",temp->days);
		temp=temp->next;
	}
}


void main(){
	addNode();
	addNode();
	printLL();
}
