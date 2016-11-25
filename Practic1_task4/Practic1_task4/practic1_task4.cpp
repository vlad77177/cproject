#include <stdio.h>

int main(char *ch){

	const double inch_in_ft=12.0;
	const double centemeter_in_inch=2.54;

	int ft=0;
	int inch=0;

	printf("American system:\n");
	printf("Enter ft=");
	scanf("%d",&ft);
	printf("Enter inch=");
	scanf("%d",&inch);

	double result=((double)inch+((double)ft*inch_in_ft))*centemeter_in_inch;
	printf("%s%.1f %s\n","European system:\nResult=",result,"sentemeter");

	int end;
	scanf("%d",&end);
	return 0;
}