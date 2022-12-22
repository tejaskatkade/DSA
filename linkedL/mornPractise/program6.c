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

int middleNode(){
    struct Node* slowPtr = head;
    struct Node* fastPtr = head;
    
    while(fastPtr->next != NULL  && fastPtr->next->next != NULL){
        
        fastPtr= fastPtr->next->next;
        slowPtr= slowPtr->next;
        
    }
    return slowPtr->data;
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
		printf("\n1.Add Node\n2.Print Data\n3.Middle NOde\n");

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
                        int middle = middleNode();
				        printf("Middle Node = %d",middle);
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
