#include <stdio.h>

void han(int num,char a,char b, char c){

	if(num>0){
		han(num-1,a,c,b);
		printf("%c--->%c\n",a,c);
		han(num-1,b,a,c);
	}
}

int main(){	

	char a,b,c;
	int num;

	printf("Enter number of rings: ");
	scanf("%d",&num);

	a='A';b='B';c='C';

	if(num>0)
		han(num,a,b,c);
	else
		puts("Error!");

	int end;
	scanf("%d",&end);

	return 0;
}