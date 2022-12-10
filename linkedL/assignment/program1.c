//WAP that searches for the first occurance, Second last occurance of a particular element from a singly linear linked list

#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
};
struct Node* head = NULL;

struct Node* createNode(){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

	printf("Enter the data\n");
	scanf("%d",&newNode->data);

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
// data occured how many times
void occurance(){
	if(head == NULL)
		printf("Linked List is Empty\n");
	else{
		int key;
		printf("Enter data to find \n");
		scanf("%d",&key);

		int flag=0;
		int loc=0;
		struct Node* temp =head;
		while(temp !=  NULL){
			loc++;
			if(key == temp->data){
				flag++;
			}
			temp=temp->next;
		}
		if(flag > 0)
			printf("Data Found At %d Position\n",flag);
		if(flag == 0 )
			printf("Data Not Found\n");
	}
}
// Finding First Occurance of data
int firstOccurance(){
	if(head == NULL)
		printf("Linked List Is Empty\n");
	else{
		int key;
		printf("Enter data to find \n");
		scanf("%d",&key);

		int flag=0;
		int loc=0;
		struct Node* temp =head;
		while(temp !=  NULL){
			loc++;
			if(key == temp->data){
				flag++;
				break;
			}

			temp=temp->next;
		}
		if(flag == 1)
			printf("Data Found At %d Position\n",loc);
		else
			printf("Data Not Found\n");
	}
}
//Finding SecondLast occurance;
void secLastOccurance(){
	if(head == NULL)
		printf("Linked List is Empty\n");
	else{
		int key;
		printf("Enter data to find \n");
		scanf("%d",&key);
		int flag =0;
		int loc=0;
		int prev=0;
		int current =0;

		struct Node* temp =head;
		while(temp !=  NULL){
			loc++;
			prev = current;
			if(key == temp->data)
			{
				flag++;
				current=loc;
			}

			temp=temp->next;
		}
		if(flag == 1)
			printf("Data Found only once at %d Position\n",current);
		if(flag > 1)
			printf("Second Last Occurance of data is %d\n",prev);
		if(flag == 0)
			printf("Data Not Found\n");
	}

}
//ADDITION OF THE DIGITS

void addDigit(){
	if(head == NULL)
		printf("Linked List is Empty\n");
	else{
		struct Node* temp = head;
		int rem=0;
		int sum=0;
		while(temp != NULL){
			int num=temp->data;
	
			while(num != 0){
				rem=num%10;
				sum=sum+rem;
				num=num/10;
			}
			temp->data=sum;
			temp=temp->next;
		}
	}
}
void palindrom(){
	struct Node* temp = head;
	int loc=0;
	int flag=0;
	if(head == NULL){
		printf("Linked List is Empty\n");
	}else{

		while(temp != NULL){
			loc++;
			int palin=0;
			int rem=0;
			int num=temp->data;
			while(num != 0)
			{
				rem = num%10;
				palin=(palin*10)+rem;
				num=num/10;
			}
			if(temp->data == palin){
				flag++;
				printf("Palindrom Found At %d\n",loc);
			}
			temp=temp->next;
		}
		if(flag == 0)
			printf("Palindrom Not Found\n");
	}
}
void printLL(){
	if(head == NULL){
		printf("Linked List Is Empty\n");
	}else{
		struct Node* temp = head;
		while(temp->next != NULL){
			printf("|%d|->",temp->data);
			temp=temp->next;
		}
		printf("|%d|\n",temp->data);
	}

}
int main(){
	int ch;
	int yn;
	while(1){
		printf("1.Add Node\n");
		printf("2.Find Data(First Occurance)\n");
		printf("3.Find Data(Second Last Occurance)\n");
		printf("4.Serch Occurance of Data\n");
		printf("5.Add the Digit\n");
		printf("6.Find If The Data Is Palindrom\n");
		printf("7.Print The Data\n");
		printf("8.Exit\n");

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
				firstOccurance();
				break;
			case 3:
				secLastOccurance();
				break;
			case 4:
				occurance();
				break;
			case 5:
				addDigit();
				break;
			case 6:
				palindrom();
				break;
			case 7:
				printLL();
				break;
			case 8:
				return 0;
			default:
				printf("Wrong Input\n");
		}
	}
}

