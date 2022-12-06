

#include <stdio.h>
#include<string.h>
#include<stdlib.h>
struct company {
	char cName[20];
	int empCount;
	float rev;

};
void main(){
	struct company *cptr = (struct company*)malloc(sizeof(struct company));
	
	strcpy(cptr -> cName,"Tata");
	cptr->empCount=45000;
	cptr->rev=80.5f;

	printf("%s\n",cptr->cName);
	printf("%d\n",cptr->empCount);
	printf("%f\n",cptr->rev);
	
	
	
}
