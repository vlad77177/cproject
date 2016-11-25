#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>

int main(char *ch){

	printf("Enter angle values in either degrees or radians. Use the symbol D for degrees or R for radians.\nExample: 45.00D\n");
	double value=0;
	double result=0;
	char symbol;
	do{
		scanf("%lf%c",&value,&symbol);
	}while((symbol=='D' || symbol=='R')==false);

	if(symbol=='D'){
		result=(value*M_PI)/180;
	}
	else{
		result=(value*180)/M_PI;
	}

	printf("%s%f %c\n","Result=",result);

	int end;
	scanf("%d",&end);
	return 0;
}