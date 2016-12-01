#include <stdio.h>

int main(){

	const int increment=2;

	int strings;

	printf("Enter the number of strings: ");
	scanf("%d",&strings);

	int indent=strings-increment;
	int stars=1;

	for(int str=1;str<=strings;str++,indent--,stars=stars+increment){
		for(int i=0;i<=indent;i++)
			printf(" ");
		for(int s=0;s<stars;s++)
			printf("%c",'*');
		printf("\n");
	}

	int end;
	scanf("%d",&end);

	return 0;
}