//structure pointer

#include<stdio.h>

struct Movie{
    char mName[20];
    int count;
    float rating;

}obj1 = {"Drishyam",10,9.9};

void main(){
    typedef struct Movie mv;

  //struct movie obj2 = { "  ",   ,  };
    mv obj2 = {"Kantara",4,9.7};
    
    mv *ptr = &obj1;  //struct movie *ptr = &obj2;
    mv *ptr1 = &obj2;

    printf("%s\n",(*ptr).mName);
    printf("%d\n",(*ptr).count);
    printf("%f\n",(*ptr).rating);

    printf("\n");

    printf("%s\n",ptr1->mName);
    printf("%d\n",ptr1->count);
    printf("%f\n",ptr1->rating);

}
