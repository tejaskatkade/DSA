// 15-12-22
//concat linked list with last n nodes 

#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};
struct Node *head1 = NULL;
struct Node *head2 = NULL;

struct Node* createNode(){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

	printf("Enter the data:\n");
	scanf("%d",&newNode->data);
	newNode->next = NULL;

	return newNode;
}
struct Node* addNode(struct Node **head){
	struct Node* newNode = createNode();

	struct Node* temp = *head;

	if(*head == NULL)
		*head = newNode;
	else{

		while(temp->next != NULL){
			temp=temp->next;
		}
		temp->next = newNode;
	
	}
	return *head;
}
int nodeCount(struct Node *head){	
	struct Node* temp = head;

	int count = 0;

	while(temp != NULL){
		count++;
		temp=temp->next;
	}
	//printf("count = %d\n",count);
	return count;

}



void concatLL(int n){
	int count = nodeCount(head2);

	int pos = count-n;
	struct Node* temp1 = head1;
	while(temp1->next != NULL){
		temp1=temp1->next;
	}
	struct Node* temp2 = head2;
	while(pos){
		temp2=temp2->next;
		pos--;
	}
	temp1->next = temp2;
	

	
}

void printLL(struct Node *head){
	struct Node *temp = head;
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
		printf("\n1.Add NOde\n2.Print Data\n3.concat last n nodes\n");

		printf("\nEnter your choice\n");
		scanf("%d",&ch);

		switch(ch){
			case 1:
				{
					int n;
					printf("\nHow many NOdes do you Want in 1st LinkedList\n");
					scanf("%d",&n);
					for(int i=0; i<n; i++){
						head1 = addNode(&head1);
					}

					printf("\nHow many NOdes do you Want in @nd LinkedList\n");
					scanf("%d",&n);
					for(int i=0; i<n; i++){
						head2 = addNode(&head2);
					}
				}
				break;
				
			case 2 :
				{
					printLL(head1);
					printLL(head2);
				}	
				break;
			case 3:
				{
					int n;
					printf("Enter num to concat last n node\n");
					scanf("%d",&n);
					concatLL(n);
				}
				break;
			default :
				printf("Wrong input\n");


		}
		getchar();
		printf("Do you want to continue ?");
		scanf("%c",&yn);
	}while(yn == 'y' || yn == 'Y');
}
