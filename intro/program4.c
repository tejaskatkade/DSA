//malloc

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct OTT{
    char pName[10];
    int userCount;
    float price;

};

void main(){
    struct OTT *ptr = (struct OTT *)malloc(sizeof(struct OTT));

    // void *vptr = malloc(sizeof(struct OTT));
    // struct OTT *ptr = (struct OTT *)vptr;

    strcpy(ptr -> pName, "Amazon prime");
    ptr -> userCount = 100;
    (*ptr).price = 299,99;

    printf("%s\n",ptr->pName);
    printf("%d\n",ptr->userCount);
    printf("%f\n",ptr->price);
}
