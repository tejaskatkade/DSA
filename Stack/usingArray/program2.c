//15-12-22 (1)

#include<stdio.h>

int top;
int arr[5];

void push(int data){
    top++;
    arr[top] = data;
}
void main(){

    printf("Enter data to push in the stack\n");
    int data;
    for(int i=0 ;i<5; i++){
        scanf("%d",&data);
        push(data);
    }

    for(int i = top; i >0; i--){
        printf("%d\n",arr[i]);
    }
    
}