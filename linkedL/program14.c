#include <stdio.h>
#include <stdlib.h>

struct demo {

	int data;
	struct demo* next;
};

struct demo* head = NULL;
struct demo* createNode(){
	struct demo* newNode = (struct demo*)malloc(sizeof(struct demo));

	printf("Enter data:\n");
	scanf("%d",&newNode->data);
	newNode->next=NULL;
	return newNode;
}

void addNode(){
	struct demo* newNode = createNode();
	
	struct demo* temp = head;

	if(head == NULL)
		head = newNode;
	else{
		while(temp->next != NULL){
			temp= temp->next;
		}
		temp->next=newNode;
	}

}
void addFirst(){
	struct demo* newNode = createNode();

	newNode->next = head;
	head = newNode;
}
int countNodes(){
	struct demo* temp= head;
	int count=0;
	while(temp!=NULL){
		count++;
		temp=temp->next;
	}
	return count;
}
void addAtPos(int pos){
	
	int count = countNodes();
	struct demo* newNode= createNode();
	struct demo* temp = head;
	
	if(pos == 1){
		newNode->next = head;
		head = newNode;
	}else if(pos == 2){
		newNode->next=head->next ;
		head->next = newNode;
	}else{
		while(pos-2){
			temp=temp->next;
			pos--;
		}

		newNode->next = temp->next;
		temp->next = newNode;
	}

}
void deleteFirst(){
	struct demo* temp = head;
	head=temp->next;
	free(temp);
}
void deleteLast(){
	struct demo* temp = head;
	while(temp->next->next!=NULL){
		temp=temp->next;
	}
	free(temp->next);
	temp->next=NULL;
}

void printLL(){
	printf("Linked List\n");

	struct demo* temp = head;
	while(temp != NULL){
		printf("| %d |",temp->data);
		temp=temp->next;
	}
}
void main()
{
	char yn;
	do{
		printf("1.Create Node\n2.Add Node at first position\n3.Add Node at position\n4.Print Nodes\n5.Delete First Node\n6.Delete Last Node\n7.Count Nodes\n");
		int ch;
		printf("Select the Option:\n");
		scanf("%d",&ch);
		
		switch(ch){
		
			case 1:
				{
					int n;
					printf("How many Nodes do you want to create");
					scanf("%d",&n);
					for(int i = 0; i<n; i++){
						addNode();
					}
			        } 
				break;
			case 2:
				addFirst();
				break;
			case 3:{
				if(head == NULL){
					printf("Create Node first\n");
				}else{
					int pos;
					printf("Enter the position:\n");
					scanf("%d",&pos);
					int count = countNodes();
			
					if(pos>count++){
						printf("Wrong position\nEnter between 1 and %d",count++);
						scanf("%d",&pos);
					}else if(pos<1){
						printf("Wrong input\nEnter between 1 and %d",count++);
						scanf("%d",&pos);
					}

					if(pos<=count++ && pos>=1){
				 		addAtPos(pos);
					}
				}
			       }
				break;
			case 4:{
					if(head == NULL){
						printf("Create Node first\n");
					}else{
						printLL();
					}
			       }
				break;
			case 5:
				{
					if(head == NULL){
						printf("Create Node first\n");
					}else{
						deleteFirst();
					}
				}
				break;
			case 6:
				{
					if(head == NULL){
						printf("Create Node first\n");
					}else{
						deleteLast();
					}
				}
				break;
			case 7:
				{
				int count=countNodes();
				printf("Total Nodes = %d\n",count);
				}
				break;
			default:
				printf("wrong choice:\n");
		}
		printf("\nDo you want to continue:\nIf YES then enter y or Y\nIf NO then enter n or N\n");
		getchar();
		scanf("%c",&yn);
	
	}while(yn == 'y' || yn =='Y');
}
