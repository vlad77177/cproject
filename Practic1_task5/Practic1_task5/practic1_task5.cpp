#include <stdio.h>

int main(){

	const int strleight=120;

	char str[strleight]="";

	printf("Please enter a string not longer than 80 symbols\n");

	scanf("%s",&str);

	int leight=0;
	while(str[leight++]);

	leight--;

	int space=0;

	if(leight%2==0){
		space=(strleight/2)-(leight/2);
	}
	else{
		space=(strleight/2)-((leight-1)/2);
	}

	for(int i=0;i<space;i++)
		printf(" ");

	printf("%s\n",str);

	int end;
	scanf("%d",&end);

	return 0;
}