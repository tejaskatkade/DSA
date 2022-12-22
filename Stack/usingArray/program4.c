//stack using Array

#include<stdio.h>
#include<stdbool.h>

int size = 0;
int top = -1;
int flag =0;

bool isEmpty(){
    if(top == -1)
        return true;
    else 
        return false;
}

bool isFull(){
    if(top == size-1)
        return true;
    else 
        return false;
}
int push(int stack[]){

    if(isFull()){
        return -1;
    }else{
        top++;
        printf("Enter the data\n");
        scanf("%d",&stack[top]);
        return 0;
    }
}

int pop(int stack[]){

    if(isEmpty()){
        flag = 0;
        return -1;
    }else{
        int ret = stack[top];
        top--;
        flag = 1;
        return ret;
    }
}

int peek(int stack[]){

    if(isEmpty()){
        flag = 0;
        return -1;
    }else{
        int ret = stack[top];
        flag = 1;
        return ret;
    }
}

void main(){
    printf("Enter the size \n");
    scanf("%d",&size); 

    int stack[size];
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
                        ret = push(stack);
                        if(ret == -1){
                            printf("Stack OverFlow\n");
                        }
                    }
                    break;
            case 2:
                    {
                        int ret;
                        ret = pop(stack);
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
                        ret = peek(stack);
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