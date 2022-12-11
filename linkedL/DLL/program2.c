//Riverse Linked List
//Method 1

#include<stdio.h>
#include<stdlib.h>

struct Node
{
	struct Node* prev;
	int data;
	struct Node* next;
};
struct Node* head = NULL;

struct Node* createNode(){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

	struct Node* prev =NULL;
	printf("Enter the data:\n");
	scanf("%d",&newNode->data);
	newNode->next = NULL;

	return newNode;
}
void addNode(){
	struct Node* newNode = createNode();

	struct Node* temp = head;

	if(head == NULL){
		head = newNode;
	}else{
		while(temp->next != NULL){
			temp=temp->next;
		}
		temp->next = newNode;
		newNode->prev = temp;
	
	}
}
int nodeCount(){	
	struct Node* temp = head;

	int count = 0;

	while(temp != NULL){
		count++;
		temp=temp->next;
	}
	//printf("count = %d\n",count);
	return count;

}

void addFirst(){
	struct Node* newNode = createNode();
	if(head == NULL){
		head = newNode;
	}else{
		newNode->next = head;
		head->prev= newNode;
		head=newNode;
	}
}
void addLast(){
	struct Node* temp = head;
	struct Node* newNode = createNode();
	
	if(head == NULL){
		head = newNode;
	}else{
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->prev = temp;
	}
}

int addAtPos(int pos){
	int count = nodeCount();

	if(pos<1 || pos > count+1){
		printf("Invalid Input\n");
		return -1;
	}else{
		if(pos == 1)
		{
			addFirst();
		}
		else if(pos == count+1)
		{
			addLast();
		}
		else
		{
			struct Node* temp = head;
			struct Node* newNode = createNode();

			while(pos-2)
			{
				temp=temp->next;
				pos--;
			}
			newNode->next = temp->next;
			newNode->prev = temp;
			temp->next->prev = newNode;
			temp->next = newNode;
		}
		return 0;
	}
}
void deleteFirst(){
	int count = nodeCount();

	if(head == NULL)
	{
		printf("No Linked List Found:\n");
	}
	else if(count ==1)
	{
		free(head);
		head = NULL;
	}
	else
	{
		head = head->next;
		free(head->prev);
		head->prev = NULL;
	}
}
void deleteLast(){
	int count =nodeCount();

	if(head == NULL){
		printf("No Linked List Found:\n");
	}else if(count == 1){
		deleteFirst();
	}else{
		struct Node* temp = head ;
		while(temp->next->next != NULL){
			temp=temp->next;
		}
		free(temp->next);
		temp->next = NULL;

	}
}

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
			struct Node* temp = head;

			while(pos -2){
				temp = temp->next;
				pos--;
			}
			temp->next = temp->next->next;
			free(temp->next->prev);
			temp->next->prev = temp;
		}

	}
}
void reverse(){
	struct Node* temp = head;

	while(temp->next != NULL){
		temp=temp->next;
	}	
	while(temp->prev != NULL){
		printf("|%d|=> ",temp->data);
		temp=temp->prev;
	}
	printf("|%d|\n",temp->data);
}

void printLL(){
	struct Node* temp = head;
	if(head == NULL){
		printf("Lined list is empty\n");
	}else{
	
		while(temp->next != NULL){
			printf("|%d|=>",temp->data);
			temp= temp->next;
		}
		printf("|%d|\n",temp->data);
	}
}
int main(){
	int ch;

	while(1)
	{
		printf("\n1.Add NOde\n2.Add At Position\n3.Delete at Position\n4.Print Data\n5.Reverse LL\n6.Exit\n");

		printf("\nEnter your choice\n");
		scanf("%d",&ch);

		switch(ch){
			case 1:
				{
					int n;
					printf("\nHow many NOdes do you Want\n");
					scanf("%d",&n);
					for(int i=0; i<n; i++){
						addNode();
					}
					printLL();
				}
				break;
				
			case 2:
				{
					int pos;
					printf("Enter the Position:\n");
					scanf("%d",&pos);
					addAtPos(pos);	
					printLL();
				}
				
				break;
			case 3:
				{
					int pos;
					printf("Enter the Position:\n");
					scanf("%d",&pos);
					deleteAtPos(pos);
					printLL();
				}
				break;
			case 4:
				printLL();
				break;
			case 5:
				reverse();
				break;
			case 6:
				return 0;
			default :
				printf("Wrong input\n");

		}
	
	}
}
