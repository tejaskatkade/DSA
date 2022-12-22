//Two stack in an array

#include<stdio.h>
#include<stdbool.h>

int size = 0;
int top1 = 0;
int top2 = 0;

int flag =0;


int push(int stack[]){

    if(top2 - top1 == 1){
        return -1;
    }else{
        int num;
        printf("Enter stack no. (1 or 2)\n");
        scanf("%d",&num);
        if(num ==1 ){
            top1++;
            printf("Enter the data\n");
            scanf("%d",&stack[top1]);
            return 0;
        }else if(num == 2){
            printf("Enter the data\n");
            top2--;
            scanf("%d",&stack[top2]);
            
            return 0;
        }else{
            printf("wrong input..\n");
        }
    }
}

int pop(int stack[]){
    int num;
    printf("Enter stack no. (1 or 2)\n");
    scanf("%d",&num);
    if(num ==1 ){
        if(top1 == -1){
            flag = 0;
            return -1;
        }else{
            int ret = stack[top1];
            top1--;
            flag = 1;
            return ret;
        }
    }else if(num == 2){
        if(top2 == size){
            flag = 0;
            return -1;
        }else{
            int ret = stack[top2];
            top2++;
            flag = 1;
            return ret;
        }
    }else{
        printf("wrong input..\n");
        pop(stack);
    }
    
}

int peek(int stack[]){

    
    int num;
    printf("Enter stack no. (1 or 2)\n");
    scanf("%d",&num);
    if(num ==1 ){
        if(top1 == -1){
            flag = 0;
            return -1;
        }else{
            int ret = stack[top1];
            flag = 1;
            return ret;
        }
    }else if(num == 2){
        if(top2 == size){
            flag = 0;
            return -1;
        }else{
            int ret = stack[top2];
            flag = 1;
            return ret;
        }
    }else{
        printf("wrong input..\n");
        pop(stack);
    }
}


void main(){
    printf("Enter the size \n");
    scanf("%d",&size); 

    int stack[size];
    top1 = -1;
    top2 = size;
    char choice;
    int ch;

    do{
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.peek\n");
        
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
            
            default:
                    printf("Wrong Choice\n");
        }
        getchar();
        printf("DO YOU WANT TO CONTINUE ?..(Y/N)\n");
        scanf("%c",&choice);
    }while(choice == 'y' || choice == 'Y');
}