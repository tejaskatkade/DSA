//stack using linked list

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head = NULL;

int size = 0;
int flag = 0;

int eleCount(){
    int count = 0;
    struct Node* temp = head;

    while(temp != NULL){
        count++;
        temp= temp->next;
    }
    return count;
}

bool isEmpty(){
    int count= eleCount();
    if(count == 0)
        return true;
    else 
        return false;
}

bool isFull(){
    if(eleCount() == size)
        return true;
    else 
        return false;
}
struct Node* createNode(){

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    printf("Enter the data\n");
    scanf("%d",&newNode->data);
    newNode->next=NULL;

    return newNode;
}

int addNode(){
    struct Node* newNode = createNode();
    if(head == NULL){
        head=newNode;
    }else{
        struct Node* temp = head;

        while(temp->next != NULL){
            temp=temp->next;
        }
        temp->next = newNode;
    }
     
}

int push(){

    if(isFull()){
        return -1;
    }else{
        addNode();
        return 0;
    }
}

int pop(){

    if(isEmpty()){
        flag = 0;
        return -1;
    }else{
        if(head->next == NULL ){
            int ret = head->data;
            printf("Return data %d\n", head->data);
            free(head);
            head = NULL;
            flag = 1; 
            return ret;            
        }else{
            struct Node* top = head;
            while(top->next->next != NULL){
                top=top->next;
            }
            int ret = top->next->data;
            printf("Return data %d\n", head->next->data);

            free(top->next);
            top->next = NULL;
            flag = 1; 
            return ret;
        } 
           
    }
}

int peek(){

    if(isEmpty()){
        flag = 0;
        return -1;
    }else{
        if(head->next == NULL ){
            flag = 1;
            return head->data;  
        }else{
            struct Node* top = head;
            while(top->next != NULL){
                top=top->next;
            }
            flag = 1;
            return top->data;  
        } 
            
    }
}

void main(){
    printf("Enter the size \n");
    scanf("%d",&size); 

    
    char choice;
    int ch;

    do{
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.peek\n");
        printf("4.isEmpty\n");
        printf("5.isFull\n");
        
        printf("Enter your choice \n");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                    {
                        int ret;
                        ret = push();
                        if(ret == -1){
                            printf("Stack OverFlow\n");
                        }
                    }
                    break;
            case 2:
                    {
                        int ret;
                        ret = pop();
                        if(flag == 0){
                            printf("Stack Under Flow\n");
                        }else{
                            printf("%d is poped\n",ret);
                        }

                    }
                    break;
            case 3:
                    {
                        int ret;
                        ret = peek();
                        if(flag == 0){
                            printf("Stack Under Flow\n");
                        }else{
                            printf("%d\n",ret);
                        }
                    }
                    break;
            case 4:
                    {
                        bool ret = isEmpty();
                        if(ret)
                            printf("Stack Is Empty\n");
                        else
                            printf("Stack Is Not Empty\n");
                    }
                    break;
            case 5:
                    {
                        bool ret = isFull();
                        if(ret)
                            printf("Stack Is Full\n");
                        else
                            printf("Stack Is Not Full\n");
                    }
                    break;
            default:
                    printf("Wrong Choice\n");
        }
        getchar();
        printf("DO YOU WANT TO CONTINUE ?..(Y/N)\n");
        scanf("%c",&choice);
    }while(choice == 'y' || choice == 'Y');
}