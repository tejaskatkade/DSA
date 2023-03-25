// Special subsequence 
// find how many times the subsequence AG has occured

#include<stdio.h>

int subsequence(char str[]){
	int count =0;
	while(*str != '\0'){
		if(*str == 'A'){
			char *temp = str;
			while(*temp != '\0'){
				if(*temp == 'G'){
					count++;
				}
				temp++;
			}
		}

		str++;
	}
	return count;

}
void main(){
	char str[200];
	printf("Enter the string\n");
	gets(str);
	int val = subsequence(str);
       	printf("%d\n",val);	

}
