#include <stdio.h>
#include <string.h>

int main(){

	const int strleight=120;

	char str[strleight];

	printf("Please enter a string not longer than 120 symbols\n");

	gets(str);

	int leight=strlen(str);

	int space=0;

	if(leight%2==0){
		space=(strleight/2)-(leight/2);
	}
	else{
		space=(strleight/2)-((leight-1)/2);
	}

	for(int i=0;i<space;i++)
		printf(" ");

	printf(str);

	int end;
	scanf("%d",&end);

	return 0;
}