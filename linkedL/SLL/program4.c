//Self refrential structure

#include<stdio.h>
#include<string.h>

typedef struct employee{
	int empId;
	char empName[20];
	float sal;
	struct employee *next;

}emp;

void main(){
	emp obj1, obj2, obj3;

	emp *head = &obj1;

	head->empId =1;
	strcpy(head->empName,"Kunal");
	head->sal = 45000.0;
	head->next = &obj2;

	head->next->empId=2;
	strcpy(head->next->empName,"Rahul");
	head->next->sal = 50000.0;
	head->next->next = &obj3;
	
	head->next->next->empId=3;
	strcpy(head->next->next->empName,"Vijay");
	head->next->next->sal = 55000.0;
	head->next->next->next= NULL;

	printf("%d\n",head->empId);
	printf("%s\n",head->empName);
	printf("%f\n",head->sal);

	printf("%d\n",head->next->empId);
	printf("%s\n",head->next->empName);
	printf("%f\n",head->next->sal);

	printf("%d\n",head->next->next->empId);
	printf("%s\n",head->next->next->empName);
	printf("%f\n",head->next->next->sal);

}
