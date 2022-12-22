//Two stack in an array

#include<stdio.h>
#include<stdbool.h>

int size = 0;
int top1 = 0;
int top2 = 0;

int flag =0;

int push1(int stack[]){

    if(top2 - top1 == 1){
        return -1;
    }else{
        top1++;
        printf("Enter the data\n");
        scanf("%d",&stack[top1]);
        return 0;
    }
}


int push2(int stack[]){

    if(top2 - top1 == 1){
        return -1;
    }else{
        top2--;
        printf("Enter the data\n");
        scanf("%d",&stack[top2]);     
        return 0;
    }
}


int pop1(int stack[]){

    if(top1 == -1){
        flag = 0;
        return -1;
    }else{
        int ret = stack[top1];
        top1--;
        flag = 1;
        return ret;
    }
}
int pop2(int stack[]){

    if(top2 == size){
        flag = 0;
        return -1;
    }else{
        int ret = stack[top2];
        top2++;
        flag = 1;
        return ret;
    }
}

int peek1(int stack[]){

    if(top1 == -1 && top2 == size){
        flag = 0;
        return -1;
    }else{
        int ret = stack[top1];
        flag = 1;
        return ret;
    }
}
int peek2(int stack[]){

    if(top1 == -1 && top2 == size){
        flag = 0;
        return -1;
    }else{
        int ret = stack[top2];
        flag = 1;
        return ret;
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
        printf("1.Push1\n");
        printf("2.Push1\n");
        printf("3.Pop1\n");
        printf("4.Pop2\n");
        printf("5.peek1\n");
        printf("6.peek2\n");
        
        printf("Enter your choice \n");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                    {
                        int ret;
                        ret = push1(stack);
                        if(ret == -1){
                            printf("Stack OverFlow\n");
                        }
                    }
                    break;
            case 2:
                    {
                        int ret;
                        ret = push2(stack);
                        if(ret == -1){
                            printf("Stack OverFlow\n");
                        }
                    }
                    break;
            case 3:
                    {
                        int ret;
                        ret = pop1(stack);
                        if(flag == 0){
                            printf("Stack Under Flow\n");
                        }else{
                            printf("%d is poped\n",ret);
                        }

                    }
                    break;
            case 4:        
                    {
                        int ret;
                        ret = pop2(stack);
                        if(flag == 0){
                            printf("Stack Under Flow\n");
                        }else{
                            printf("%d is poped\n",ret);
                        }

                    }
                    break;
            case 5:
                    {
                        int ret;
                        ret = peek1(stack);
                        if(flag == 0){
                            printf("Stack Under Flow\n");
                        }else{
                            printf("%d\n",ret);
                        }
                    }
                    break;
            case 6:
                    {
                        int ret;
                        ret = peek2(stack);
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