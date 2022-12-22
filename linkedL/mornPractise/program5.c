
//Inplace REverse 
// DCLL


void main(){
	
	char yn;
	int ch;

	do{
		printf("\n1.Add Node\n2.Print Data\n3.Count\n4.Reverse\n");

		printf("\nEnter your choice\n");
		scanf("%d",&ch);

		switch(ch){
			case 1:
				{
					int n;
					printf("\nHow many NOdes do you Want\n");
					scanf("%d",&n);
					for(int i=0; i<n; i++){
						addNode();
					}
					printLL();
				}
				break;
				
			case 2:
				printLL();
				break;
				
				
			case 3:
				{
					int count = nodeCount();
					printf("count is %d",count);
				}
				break;

			case 4:
				inplaceRev();
				break;
			default :
				printf("Wrong input\n");


		}
		getchar();
		printf("Do you want to continue ?");
		scanf("%c",&yn);
	}while(yn == 'y' || yn == 'Y');
}
