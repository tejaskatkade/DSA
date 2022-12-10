//SINGLY LINKED LIST

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
	while(*str != '\0'){
		len++;
		str++;
	}
	return len;
}
void length(){
	int num;
	printf("Enter the Number\n");
	scanf("%d",&num);

	struct Node* temp = head;
	
	int len = mystrlen((*temp).str);
	//printf("%d\n",len);
	
	while(temp != NULL){
		int len = mystrlen(temp->str);
		//printf("%d",len);
		if(len == num)
			printf("%s\n",temp->str);	

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
		printf("2.Find Data Of Particular Length\n");
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
				length();
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

