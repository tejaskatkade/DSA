//SINGLY LINKED LIST  reverse the string

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
char* mystrrev(char *str){
	char *temp =str;
	while(*temp != '\0'){
		temp++;
	}
	temp--;
	char ch;
	while(str < temp){
		ch = *str;
		*str =*temp;
		*temp = ch;
		str++;
		temp--;
	}
	return str;
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
void reverseData(){
	struct Node* temp = head;
	while(temp != NULL){
		mystrrev(temp->str);
		temp=temp->next;
	}
	printLL();
}

int main(){
	int ch;
	int yn;
	while(1){
		printf("1.Add Node\n");
		printf("2.Reverse\n");
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
				reverseData();
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

