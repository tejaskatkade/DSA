//Structure:

#include<stdio.h>
#include<string.h>

struct crickPlayer{
    int jerNo;
    char pName[10];
    float sal;
}obj1 = {18,"virat",5.0};

void main(){
    struct crickPlayer obj2;

    obj2.jerNo = 45;
    strcpy(obj2.pName, "Rohit");
    obj2.sal = 5.0;

    printf("%d\n",obj1.jerNo);
    printf("%s\n",obj1.pName);
    printf("%f\n",obj1.sal);
    
    printf("%d\n",obj2.jerNo);
    printf("%s\n",obj2.pName);
    printf("%f\n",obj2.sal);
    

}