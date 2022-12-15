#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node* prev;
	int data;
	struct Node *next;
};
struct Node *head = NULL;

struct Node *createNode()
{
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->prev = NULL;
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
        head->prev = head;
	}
	else
	{
		// struct Node *temp = head;
		// while (temp->next != head)
		// {
		// 	temp = temp->next;
		// }
		// temp->next = newNode;
        // newNode->prev = temp;
		// newNode->next = head;
        // head->prev = newNode;

        head->prev->next = newNode;
        newNode->prev = head->prev;
        newNode->next = head;
        head->prev = newNode;
	}
}
void addFirst()
{

	struct Node *newNode = createNode();
	struct Node *temp = head;
	if (head == NULL)
	{
		head = newNode;
		newNode->next =  head;
        newNode->prev =  head;

	}	
	else
	{
		head->prev->next = newNode;
		newNode->prev = head->prev;
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
		
    }
}
void addLast()
{
	struct Node *newNode = createNode();
	struct Node *temp = head;
	
	if (head == NULL)
	{
		head = newNode;
		newNode->prev =  head;
		newNode->next =  head;
	}
	else
	{
		

		head->prev->next = newNode;
		newNode->prev =head->prev;
		newNode->next = head;
		head->prev = newNode;
		}
}
int countNode()
{
	struct Node *temp = head;
	int count = 0;
	if(head == NULL){
		return count;
	}else{
		while (temp->next!= head)
		{
			count++;
			temp = temp->next;
		}
		count++;
		return count;
	}
}
void addAtPos(int pos)
{
	int count = countNode();

	struct Node *temp = head;

	if (pos > count + 1 || pos < 1)
		printf("Invalid Position\n");
	else
	{
		if (pos == count + 1)
			addLast();
		else if (pos == 1)
			addFirst();
		else
		{
			struct Node *newNode = createNode();
			while (pos - 2)
			{
				temp = temp->next;
				pos--;
			}
			newNode->next = temp->next;
			newNode->prev = temp;
			temp->next = newNode;
			newNode->next->prev = newNode;
		}
	}
}

void deleteFirst(){
	if(head == NULL){
		printf("Linked List is Empty\n");
	}else{
		if(head->next == head){
			free(head);
			head = NULL;
		}else{
			head->next->prev = head->prev;
			head = head->next;
			free(head->prev->next);
			head->prev->next = head;
		}
	}

}

void deleteLast(){
	struct Node* temp = head;
	if(head == NULL){
		printf("Linked List Is Empty\n");
	}else{
		if(head->next == head)
		{
			free(head);
			head = NULL;
		}
		else{
			head->prev = head->prev->prev;
			free(head->prev->next);
			head->prev->next = head;
		}
	}
}

void deleteAtPos(int pos){
	struct Node* temp= head;
	int count = countNode();

	if(pos < 1 || pos > count){
		printf("Invalid operation\n");
	}else{
		if(pos == 1){
			deleteFirst();
		}else if(pos == count){
			deleteLast();
		}else{
			while(pos-2){
				temp=temp->next;
				pos--;
			}
			temp->next = temp->next->next;
			free(temp->next->prev);
			temp->next->prev = temp;
		}
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

int main()
{

	int ch;
	while (1)
	{
		printf("1.ADD NODES\n");
		printf("2.ADD FIRST\n");
		printf("3.ADD LAST\n");
		printf("4.ADD AT POS\n");
		printf("5.Delete first\n");
		printf("6.Delete Last\n");
		printf("7.Delete at Position\n");	
		printf("8.print NODES\n");
		printf("9.count\n");
		printf("10.Exit\n");

		printf("\nEnter your choice:\n");
		scanf("%d", &ch);

		switch (ch)
		{
		case 1:
		{
			int n;
			printf("How Many Nodes Do You Want?\n");
			scanf("%d", &n);
			for (int i = 0; i < n; i++)
				addNode();
		}
		break;
		case 2:
			addFirst();
			break;
		case 3:
			addLast();
			break;
		case 4:
		{
			int pos;
			printf("Enter Position\n");
			scanf("%d", &pos);
			addAtPos(pos);
		}
		break;
		case 5:
			deleteFirst();
			break;
		case 6:
			deleteLast();
			break;
		case 7:	{
				int pos;
				printf("Enter the Position\n");
				scanf("%d",&pos);
				deleteAtPos(pos);
			}
			break;
		case 8:
			printLL();
			break;
		case 9:
		{
			int count = countNode();
			printf("count is %d\n", count);
		}
			break;
		case 10:
			return 0;
		default:
			printf("You Entred Wrong Input");
		}
	}
}
