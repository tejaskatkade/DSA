//Circular Queue

#include<stdio.h>
#include<stdlib.h>

int size;
int front = 0;
int rear = 0;
int flag = 0;

int enqueue(int arr[]){
	if(( front == 0 && rear == size-1 )||( front-rear == 1 )){
		return -1;
	}else{
		if(front == -1){
			front++;
			rear++;
		}else{
			if(rear == size-1 && front != 0){
				rear = -1;
			}
			rear++;	
		}

		printf("Enter data\n");
		scanf("%d",&arr[rear]);
		return 0;
	}
}
int dequeue(int arr[]){
	if(front == -1){
		flag = 0;
		return -1;
	}else{
		flag = 1;
		int val = arr[front];
		if(rear == front){
			front = -1;
			rear = -1;
		}else{
			if(front == size-1){
				front =-1;
			}
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
		int val = arr[front];
		return val;
	}

}
void printQue(int arr[]){
	if(front == -1){
		printf("Queue is empty\n");
	}else{
		int i=front;
		while(i !=  rear){
			printf("%d",arr[i]);
			if(i == size-1){
				i = -1;
			}
			i++;
		}
		printf("%d\n",arr[rear]);
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
                    printQue(arr);
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
