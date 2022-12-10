//SINGLY LINKED LIST
//
//WAP that accepts  a sinlgy linear linked list from the user.
//Take a number from the user and only keep the elements that are equal in length to that number and delete other elements. And print the Linked list length of shashi=6

#include<stdio.h>
#include<stdlib.h>

struct Node{
	char str[20];
	struct Node* next;
};
struct Node* head = NULL;

struct Node* createNode(){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	getchar();
	printf("Enter the data\n");
	int i=0;
	char ch;
	
	while((ch=getchar()) != '\n')
		(*newNode).str[i++]=ch;
	(*newNode).str[i]='\0';
	newNode->next=NULL;
	return newNode;
}
void addNode(){
	struct Node* newNode = createNode();

	if(head == NULL){
		head = newNode;
	}else{
		struct Node* temp = head;
		while(temp->next != NULL){
			temp=temp->next;
		}
		temp->next = newNode; 
	}

}
int mystrlen(char *str){
	int len=0;
	while(*str != '\n'){
		len++;
		str++;
	}
	return len;
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

void delAtPos(int pos){
	
	int count = nodeCount();

	if(pos < 1 || pos > count ){
		printf("Invalid Position\n");
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
int delStr(){
	int num;
	printf("Enter the Number(length of str)\n");
	scanf("%d",&num);

	int pos =0;
	struct Node* temp = head;
	
	while(temp != NULL){
		pos++;
		
		int length =0;
		int i=0;
		while((*temp).str[i] != '\0'){
			length++;
			i++;
		}

		if(length != num)
		{
			delAtPos(pos);
			pos--;
		}	
		temp=temp->next;
	}
}

void printLL(){
	if(head == NULL){
		printf("Linked List Is Empty\n");
	}else{
		struct Node* temp = head;
		while(temp->next != NULL){
			printf("|%s|->",temp->str);
			temp=temp->next;
		}
		printf("|%s|\n",temp->str);
	}

}
int main(){
	int ch;
	int yn;
	while(1){
		printf("1.Add Node\n");
		printf("2.Delete string other than Particular Length\n");
		printf("3.Print The Data\n");
		printf("4.Exit\n");

		printf("Enter Choice\n");
		scanf("%d",&ch);

		switch(ch){
			case 1:
				{

					int num;
					printf("How Many Nodes Do U Want To Print ?\n");
					scanf("%d",&num);
					for(int i=0; i<num; i++)
					{
						addNode();
					}
										
				}
				break;
			case 2:
				delStr();
				break;
			case 3:
				printLL();
				break;
			case 4:
				return 0;
			default:
				printf("Wrong Input\n");
		}
	}
}

