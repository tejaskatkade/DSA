// SCLL

#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};
struct Node *head = NULL;

struct Node *createNode()
{
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

	printf("Enter the data:\n");
	scanf("%d", &newNode->data);
	newNode->next = NULL;
}

void addNode()
{
	struct Node *newNode = createNode();

	if (head == NULL)
	{
		head = newNode;
		head->next = head;
	}
	else
	{
		struct Node *temp = head;
		while (temp->next != head)
		{
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->next = head;
	}
}

void printLL()
{
	struct Node *temp = head;
	if (head == NULL)
	{
		printf("Linked List is empty\n");
	}
	else
	{
		while (temp->next != head)
		{
			printf("|%d|=>", temp->data);
			temp = temp->next;
		}
		printf("|%d|\n", temp->data);
	}
}




void inplaceRev(){
	struct Node* temp1 = NULL;
	struct Node* ptr = head;
	struct Node* temp2 = NULL;

	while(temp2 != head ){
		temp2 = ptr->next;
		ptr->next = temp1;
		temp1 = ptr;
		ptr = temp2;

	}
		ptr->next = temp1;
		head = temp1;
}





void main(){
	
	char yn;
	int ch;

	do{
		printf("\n1.Add Node\n2.Print Data\n3.Reverse\n");

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
