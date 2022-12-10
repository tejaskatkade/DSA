//07-12-22

#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};
struct Node* head = NULL;

struct Node* createNode(){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

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
	}
}

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
			struct Node* temp = head;
			struct Node* newNode = createNode();

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
void deleteFirst(){
	if(head == NULL){
		printf("No Linked List Found:\n");
	}else{
		struct Node* temp = head;
		head = temp->next;
		free(temp);
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
			struct Node* ptr = temp->next;

			temp->next = temp->next->next;
			free(ptr);
		}

	}
}

void findNode(){
	struct Node* temp = head;
	int key;
	int flag =0;
	int loc=0;
	int current=0, prev=0;
	printf("Enter data to find:\n");
	scanf("%d",&key);

	while(temp!=NULL){
		loc++;
		if(key == temp->data){
			prev = current;
			current=loc;
			flag++;
		}	
		temp=temp->next;
	}
	printf("Element found %d times\n",flag);

	if(flag == 1){
		printf("data found at position %d\n",current);
	}
	if(flag > 1){
		printf("last occurance is %d\n",prev);
	}
	
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
void main(){
	
	char yn;
	int ch;

	do{
		printf("\n1.Add NOde\n2.Add First\n3.Add Last\n4.Add At Position\n5.Delete First\n6.Delete Last\n7.Delete at Position\n8.Print Data\n9.count\n10.Find data\n");

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
					printf("count is %d",count);
				}
				break;
			case 10:
				{
					findNode();
					break;
				}
			default :
				printf("Wrong input\n");


		}
		getchar();
		printf("Do you want to continue ?");
		scanf("%c",&yn);
	}while(yn == 'y' || yn == 'Y');
}
