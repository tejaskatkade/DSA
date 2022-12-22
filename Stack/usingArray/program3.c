
//S

#include<stdio.h>
int size;
int top = -1;
int flag=0;

void displayStack(int *stack){

        for(int i=top; i>-1; i--){
            printf("|%d|",stack[i]);
            if(i == top ){
                printf(" <-- Top");
                printf("\n");
            }else{
                printf("\n");
            }
        }
        
        printf("\n\n");
    
}
void push(int *stack, int data){

    top++;
    stack[top] = data;
    printf("%d is pushed successfully\n",data);
    displayStack(stack);
}

int pop(int *stack){

    if(top == -1){
        printf("Stack Underflow\n");
        flag = 1;
        return -1;
    }else{
        int data = stack[top];
        top--;
        
        return data;
    }
}

int peek(int *stack){
    if(top == -1){
        printf("Wrong operation\n");
    }else{
        int data = stack[top];
        return data;
    }


}

// void getData(int *stack, int index){
//     if(index < 1 || index > top+1){
//         printf("Invalid Index\n");
//     }else{
        
//         printf("%d\n",stack[top-index+1]);
            
//     }
// }

int main(){
    
    printf("Enter the size stack\n");
    scanf("%d",&size);

    int stack[size];

    //system('clear');
    int ch;
    while(1){
        printf("1.push data\n2.pop data\n3.peek data\n4.Display stack\n5.exit\n\nEnter your choice:\n");
        scanf("%d",&ch);

        switch(ch){

            case 1:
                {
                    if(top == size-1){
                        printf("Stack Overflow\n");
                    }else{
                        int data;
                        printf("Enter data to push\n");
                        scanf("%d",&data);
                        push(stack,data);
                    }

                }
                break;
            case 2:
                {
                    int data = pop(stack);
                    if(flag == 0){                    
                        printf("%d is poped succesfully\n\n",data);
                        displayStack(stack);
                    }else{
                        flag = 0;
                    }
                }
                break;
            case 3:
                {
                    if(top == -1){
                        printf("stack is underflow\n");
                    }else{
                        int data = peek(stack);
                        printf("%d \n",data);
                    }

                }
                break;
            case 4:
                displayStack(stack);
                break;
            case 5:
                return 0;
            default:
                printf("Wrong choice\n");

        }

    }
}