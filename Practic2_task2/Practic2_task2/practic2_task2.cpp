#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

	const int min=1;
	const int max=100;

	int start_time=time(NULL);
	srand(start_time);

	int value=min+rand()%max;

	printf("We made a number from one to one hundred. Enter this number:\n");
	
	bool endgame=false;

	do{

		int ansver;
		printf("%s","Enter number: ");
		scanf("%d",&ansver);
		if(ansver==value)
			endgame=true;
		else if(ansver>value)
			printf("The unknown number less\n");
		else
			printf("The unknown number more\n");

	}while(endgame!=true);

	printf("You win!!!\n");
	
	int end;
	scanf("%d",&end);
}