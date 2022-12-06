// pointer

#include<stdio.h>
void main(){
    char carr[5]={'A','B','C','D','E'};

    char *cptr = carr;
    int *iptr = carr;  //warning: initialization of ‘int *’ from incompatible pointer type ‘char *

    printf("%c\n",*cptr);  //A
    printf("%c\n",*iptr);  //A
    
    cptr++;
    iptr++;

    printf("%c\n",*cptr);  //B
    printf("%c\n",*iptr);  //E
    
}