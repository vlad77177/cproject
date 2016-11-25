#include <stdio.h>

int main(char *ch){

	const char normal[]="Your body mass index normal";
	const char to_gain_weight[]="You should gain weight";
	const char to_lose_weight[]="You should lose weight";

	const double bmi_min_forman=20.0;
	const double bmi_max_forman=25.0;
	const double bmi_min_forwoman=19.0;
	const double bmi_max_forwoman=24.0;

	int gender=0;
	double height=0;
	double mass=0;

	do{
		printf("Enter your gender: 1 - man, 2 - women\n");
		scanf("%d",&gender);
	}while((gender==1 || gender==2)==false);

	printf("Enter your height(in meters):\n");
	scanf("%lf",&height);

	printf("Enter your mass(in kilograms):\n");
	scanf("%lf",&mass);

	printf("%f\n",height);
	printf("%f\n",mass);

	double bmi=mass/(height*height);

	printf("%s%f\n","Your body mass index: ",bmi);

	switch(gender){
	case 1:
		{
			if(bmi>=bmi_min_forman && bmi<=bmi_max_forman)
				printf(normal);
			else
			{
				if(bmi<bmi_min_forman)
					printf(to_gain_weight);
				if(bmi>bmi_max_forman)
					printf(to_lose_weight);
			}
			break;
		}
	case 2:
		{
			if(bmi>=bmi_min_forwoman && bmi<=bmi_max_forwoman)
				printf(normal);
			else
			{
				if(bmi<bmi_min_forman)
					printf(to_gain_weight);
				if(bmi>bmi_max_forman)
					printf(to_lose_weight);
			}
			break;
		}
	}
	int end;
	scanf("%d",&end);
}