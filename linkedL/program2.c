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
	
	obj1.empId =1;
	strcpy(obj1.empName,"Kunal");
	obj1.sal = 45000.0;
	obj1.next = &obj2;

	obj2.empId=2;
	strcpy(obj2.empName,"Rahul");
	obj2.sal = 50000.0;
	obj2.next = &obj3;
	
	obj3.empId=3;
	strcpy(obj3.empName,"Vijay");
	obj3.sal = 55000.0;
	obj3.next = NULL;

	printf("%d\n",obj1.empId);
	printf("%s\n",obj1.empName);
	printf("%f\n",obj1.sal);

	printf("%d\n",obj2.empId);
	printf("%s\n",obj2.empName);
	printf("%f\n",obj2.sal);

	printf("%d\n",obj3.empId);
	printf("%s\n",obj3.empName);
	printf("%f\n",obj3.sal);







}
