//SINGLY LINKED LIST 

#include<stdio.h>
#include<stdlib.h>

typedef struct webBrowser
{
	char pName[20];
 	struct webBrowser* next;
}Node;

Node* head = NULL;

Node* createNode(){
	Node* newNode = (Node*)malloc(sizeof(Node));
	getchar();
	int i=0;
	char ch;
	printf("Enter web page name :\n");
	while((ch=getchar()) != '\n'){
		(*newNode).pName[i++]=ch;
	}
	newNode->next = NULL;
	return newNode;
}

// ADDING NODE

void addNode(){
	Node* newNode = createNode();

	Node* temp = head;

	if(head == NULL){
		head = newNode;
	}else{
		while(temp->next != NULL){
			temp=temp->next;
		}
		temp->next = newNode;
	
	}
}
int nodeCount(){	
	Node* temp = head;

	int count = 0;

	while(temp != NULL){
		count++;
		temp=temp->next;
	}
	//printf("count = %d\n",count);
	return count;

}
//ADDING NODE AT 1ST POSITION
void addFirst(){
	Node* newNode = createNode();
	if(head == NULL){
		head = newNode;
	}else{
		newNode->next = head;
		head=newNode;
	}
}

//ADDING NODE AT LAST POSITION

void addLast(){
	Node* temp = head;
	Node* newNode = createNode();
	
	if(head == NULL){
		head = newNode;
	}else{
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = newNode;
	}
}
//ADDING NODE AT SPECIFIC POSITION
int addAtPos(int pos){
	int count = nodeCount();

	if(pos<1 || pos > count+1){
		printf("Invalid Input\n");
		return -1;
	}else{
		if(pos == 1){
			addFirst();
		}else if(pos == count++){
			addLast();
		}else{
			Node* temp = head;
			Node* newNode = createNode();

			while(pos-2){
				temp=temp->next;
				pos--;
			}
			newNode->next = temp->next;
			temp->next = newNode;
		}
		return 0;
	}
}
//DELETING FIRST NODE
void deleteFirst(){
	if(head == NULL){
		printf("No Linked List Found:\n");
	}else{
		Node* temp = head;
		head = temp->next;
		free(temp);
	}
}
//DELETING LAST NODE
void deleteLast(){
	int count =nodeCount();

	if(head == NULL){
		printf("No Linked List Found:\n");
	}else if(count == 1){
		deleteFirst();
	}else{
		Node* temp = head ;
		while(temp->next->next != NULL){
			temp=temp->next;
		}
		free(temp->next);
		temp->next = NULL;

	}
}
//DELETING NODE AT SPECIFIC  POSITION
int deleteAtPos(int pos){
	
	int count = nodeCount();

	if(pos < 1 || pos > count ){
		printf("Invalid Position\n");
		return -1;
	}else{
		if(pos == 1)
			deleteFirst();
		else if(pos == count)
			deleteLast();
		else{
			Node* temp = head;

			while(pos -2){
				temp = temp->next;
				pos--;
			}
			Node* ptr = temp->next;

			temp->next = temp->next->next;
			free(ptr);
		}

	}
}
//PRINTING NODE
void printLL(){
	Node* temp = head;
	if(head == NULL){
		printf("No web page Found\n");
	}else{
	
		while(temp->next != NULL){
			printf("|%s|=>",temp->pName);
			temp= temp->next;
		}
		printf("|%s|\n",temp->pName);
	}
}
void main(){
	
	char yn;
	int ch;

	do{
		//system("clear");
		printf("========MENU========\n");
		printf("1.Add Node\n");
		printf("2.Add First\n");
		printf("3.Add Last\n");
		printf("4.Add At Position\n");
		printf("5.Delete First\n");
		printf("6.Delete Last\n");
		printf("7.Delete at Position\n");
		printf("8.Print Data\n");
		printf("9.count\n");
		
		printf("Enter your choice\n");
		scanf("%d",&ch);

		switch(ch){
			case 1:
				{
					int n;
		
					printf("How many web pages do you Want\n");
					scanf("%d",&n);
					for(int i=0; i<n; i++){
						addNode();
					}
					printLL();
				}
				break;
				
			case 2:
				addFirst();
				printLL();
				break;
				
				
			case 3:
				addLast();
				printLL();	
				break;

			case 4:
				{
					int pos;
					printf("Enter the Position:\n");
					scanf("%d",&pos);
					addAtPos(pos);	
					printLL();
				}
				
				break;
			case 5:
				deleteFirst();		
				printLL();
				break;
			case 6:
				deleteLast();
				printLL();
				break;

			case 7:
				{
					int pos;
					printf("Enter the Position:\n");
					scanf("%d",&pos);
					deleteAtPos(pos);
					printLL();
				}
				break;
			case 8:
				printLL();
				break;
			case 9:
				{
					int count = nodeCount();
					printf("count is %d\n",count);
				}
				break;
			default :
				printf("Wrong input\n");


		}
		getchar();
		printf("Do you want to continue ?(Y/N)\n");
		scanf("%c",&yn);
	}while(yn == 'y' || yn == 'Y');
}
