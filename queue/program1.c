//Linear Queue using Array
#include<stdio.h>
#include<stdlib.h>


int size=0;
int front=0;
int rear=0;
int flag=0;

int enqueue(int arr[]){

    if(rear == size-1){
        flag = 0;
        return -1;
    }else{
        flag = 1;
        if(front == -1){
            front++;
        }
        rear++;
        printf("Enter data\n");
        scanf("%d",&arr[rear]);
        return arr[rear];
    }
}

int dequeue(int arr[]){

    if(front == -1){
        flag = 0;
        return -1;
    }else{
        flag = 1;
        int val = arr[front];
        if(front == rear){
            front = -1;
            rear = -1;
        }else{
            front++;
        }
        return val;
    }
}
int frontt(int arr[]){
    if(front == -1){
        flag = 0;
        return -1;
    }else{
        flag = 1;
        return arr[front];
    }
}

int  printQue(int arr[]){
    if(front == -1){
        flag = 0;
        return -1;
    }else{
        flag = 1;
        for(int i=front; i<=rear; i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
        return 0;
    }
}
void main(){

    printf("Enter the size of an array\n");
    scanf("%d",&size);
    front = -1;
    rear =  -1;
    int arr[size];

    while(1){
        int ch;
        printf("1.Enqueue\n2.Dequeue\n3.front\n4.printf\n5.Exit\n\nSelect your choice\n");
        scanf("%d",&ch);

        switch(ch){

            case 1:
                {
                   int val = enqueue(arr);
                    if( val == -1){
                        printf("Queue is full...\n");
                    }else{
                        printf("%d is enqueued\n",val);
                    }
                }
                break;
            case 2:
                {
                    int val = dequeue(arr);
                    if(flag == 0){
                        printf("Queue is empty...\n");
                    }else{
                        printf("%d is dequeued\n",val);
                    }

                }
                break;
            case 3:
                {
                    int val = frontt(arr);
                    if(flag == 0){
                        printf("Queue is empty...\n");
                    }else{
                        printf("%d \n",val);
                    }

                }
                break;
            case 4:
                {
                    int val = printQue(arr);
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