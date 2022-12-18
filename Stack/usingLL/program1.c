#include<stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
};

int size;
int flag=0;
struct Node* top = NULL;

int countNode(){
    int count=0;
    struct Node*  temp = top;
    while(temp != NULL){
        count++;
        temp=temp->next;
    }
    return count;

}
void printStack(){
    int count = countNode();

    if(count == 0){
        printf("Stack UnderFlow\n");

    }else{
        struct Node* temp = top;

        while(temp != NULL){
            printf("|%d|",temp->data);
            if(temp == top){
                printf("  <-- TOP");
            }
            printf("\n");
            temp=temp->next;
        }
        printf("\n");
    }
}
int push(){
    int count = countNode();
    
    if(count == size ){
            printf("Stack OverFlow..\n");
            return -1;
    }else{
            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

            printf("Enter data:\n");
            scanf("%d",&newNode->data);
            if(top == NULL){
                top = newNode;
                newNode->next = NULL;
            }else{
                newNode->next = top;
                top = newNode;
            }
            printf("%d pushed successfully\n",newNode->data);
            printStack();
           
    }
}

int pop(){
    int count = countNode();
    if(count == 0){
        printf("Stack UnderFlow\n");
        flag = 1;
        return -1;
    }else{
        struct Node* temp = top;
        top=top->next;
        return temp->data;
        free(temp);
        printf("Data popped successfully\n");
        printStack();
        
    }
}
int peek(){
    int count = countNode();
    if(count == 0){
        printf("Stack UnderFlow\n");
        flag = 1;
        return -1;
    }else{
        int data = top->data;
        return data;
    }
}


int main(){
    int ch;
    printf("Enter size\n");
    scanf("%d",&size);

    while(1){
        printf("Enter your choice\n");
        printf("1.push\n2.pop\n3.peek\n4.print data\n5.Exit\n");

        scanf("%d",&ch);

        switch(ch){
            case 1:
                push();
            break;
            
            case 2:
                {
                    int data = pop();
                    if(flag == 0){
                        printf(" %d poped Successfully..\n",data );
                        printStack();
                    }else{
                        flag = 0;
                }
                break;
            case 3:
                {
                    int data = peek();
                    if(flag ==0){
                        printf("\n|%d|  <-- TOP\n",data);
                    }else{
                        flag =1;
                    }
                }break;
            case 4:
                printStack();
                break;
            case 5:
                return 0;
            default:
                printf("Wrong choice\n" );
                }
        }
    }
}
