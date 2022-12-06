#include<stdio.h>

struct rectangle{
	int length;
	int breadth;
};

void initialize(struct rectangle *r,int l, int b){

	(*r).length=l;
	r->breadth=b;
}

int area(struct rectangle r){

	int a = r.length * r.breadth;
	return a;
}

void changeLength(struct rectangle *r, int l,int b){
	r->length=l;
	r->breadth=b;
}

void main(){

	struct rectangle r;
	
	int len,bre;
	printf("Enter the value of length and breadth:\n");
	scanf("%d %d",&len,&bre);

	initialize(&r, len, bre);

	printf("The area of the Rectangle is:\n");
	int a = area(r);
	printf("%d\n",a);

	printf("Enter the value to change the length and breadth:\n");
	scanf("%d %d",&len,&bre);
	changeLength(&r,len,bre);
	

}
