//INPLACE RERVERSE 
//SINGLY LINEAR LINKED LIST

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

	return count;

}
void inplaceRev(){
	struct Node* temp1 = NULL;
	struct Node* temp2 = head;

	while(head != NULL ){
		head = head->next;
		temp2->next = temp1;
		temp1 = temp2;
		temp2 = head;

	}
		head = temp1;
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
		printf("\n1.Add Node\n2.Print Data\n3.Count\n4.Reverse\n");

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
				printLL();
				break;
				
				
			case 3:
				{
					int count = nodeCount();
					printf("count is %d",count);
				}
				break;

			case 4:
				inplaceRev();
				break;
			default :
				printf("Wrong input\n");


		}
		getchar();
		printf("Do you want to continue ?");
		scanf("%c",&yn);
	}while(yn == 'y' || yn == 'Y');
}
