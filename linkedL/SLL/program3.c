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

	obj1.next->empId=2;
	strcpy(obj1.next->empName,"Rahul");
	obj1.next->sal = 50000.0;
	obj1.next->next = &obj3;
	
	obj2.next->empId=3;
	strcpy(obj2.next->empName,"Vijay");
	obj2.next->sal = 55000.0;
	obj2.next-> next= NULL;

	printf("%d\n",head->empId);
	printf("%s\n",head->empName);
	printf("%f\n",head->sal);

	printf("%d\n",obj1.next->empId);
	printf("%s\n",obj1.next->empName);
	printf("%f\n",obj2.next->sal);

	printf("%d\n",obj3.empId);
	printf("%s\n",obj3.empName);
	printf("%f\n",obj3.sal);







}
