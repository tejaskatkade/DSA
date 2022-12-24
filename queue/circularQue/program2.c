//Circular Queue
//using singly circular linked list
#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	struct Node* next;
}Node;

Node* front = NULL;
Node* rear = NULL;
int flag = 0;
int size=0;

Node* createNode(){

	Node* newNode = (Node*)malloc(sizeof(Node));

	printf("Enter data\n");
	scanf("%d",&newNode->data);
	newNode->next = NULL;
	return newNode;
}
int nodeCount(){
	int count=0;
	if(front == NULL){
		return count;
	}else{
		Node* temp=front;
		while(temp != rear){
			count++;
			temp= temp->next;
		}
		count++;
		return count;
	}
	
}
int enqueue(){

	int count = nodeCount();
	if(count == size){
		return -1;
	}else{
		Node* newNode = createNode();
		if(front == NULL){
			front=newNode;
			newNode->next=front;
			rear = newNode;
		}else{
			rear->next=newNode;
			newNode->next = front;
			rear=newNode;
		}
		return 0;
	}
}
int dequeue(){
	if(front == NULL){
		flag = 0;
		return -1;
	}else{
		flag = 1;
		int val = front->data;
		if(front->next == front){
			free(front);
			front = NULL;
			rear = NULL;
		}else{
			front = front->next;
			free(rear->next);
			rear->next = front;
		}
		return val;
	}
}
int frontt(){
	if(front == NULL){
		flag = 0;
		return -1;
	}else{
		flag = 1;
		int val = front->data;
		return val;
	}

}
void printQue(){
	if(front == NULL){
		printf("Queue is Empty");
	}else{
		Node* temp = front;
		while(temp != rear){
			printf("%d ->",temp->data);
			temp=temp->next;
		}
		printf("%d\n",temp->data);
	}
}
void main(){
	
    printf("Enter the size\n");
    scanf("%d",&size);

    while(1){
        int ch;
        printf("1.Enqueue\n2.Dequeue\n3.front\n4.printf\n5.Exit\n\nSelect your choice\n");
        scanf("%d",&ch);

        switch(ch){

            case 1:
                {
                   int val = enqueue();
                    if( val == -1){
                        printf("Queue is full...\n");
                    }
                }
                break;
            case 2:
                {
                    int val = dequeue();
                    if(flag == 0){
                        printf("Queue is empty...\n");
                    }else{
                        printf("%d is dequeued\n",val);
                    }

                }
                break;
            case 3:
                {
                    int val = frontt();
                    if(flag == 0){
                        printf("Queue is empty...\n");
                    }else{
                        printf("%d \n",val);
                    }

                }
                break;
            case 4:
                {
                    printQue();
                    if(flag == 0){
                        printf("Queue is empty...\n");
                    }  

                }
                break;
            case 5:
                exit(1);
                break;
            default:
                printf("Your choice is WRONG !!!\n");
        }
    }
}
