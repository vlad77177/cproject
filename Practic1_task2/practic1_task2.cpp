#include <stdio.h>

int main(char *ch){

	const int morning=21600;
	const int day=43200;
	const int evening=64800;

	int hour,minute,second;

	do{
		printf("Enter time in the format HH:MM:SS\n");
		scanf("%d:%d:%d",&hour,&minute,&second);
	}while(((hour>=0 && hour<=23) && (minute>=0 && minute<=59) && (second>=0 && second<=59))==false);

	int daysecond=second+(minute*60)+(hour*3600);	//seconds since the beginning of the day

	if(daysecond<morning)
		printf("Good night");
	else if(daysecond<day)
		printf("Good morning");
	else if(daysecond<evening)
		printf("Good day");
	else
		printf("Good evening");

	int end;
	scanf("%d",&end);
	return 0;
}