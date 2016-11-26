#include <stdio.h>
#include <time.h>

void wait(int ms){
	int c=clock()+ms;
	while(clock()<c);
}

int main(){

	const double g=9.81;
	const int sec=1000;

	double startheight=0;
	double height=0;
	int t=0;

	printf("Enter the height=");
	scanf("%lf",&startheight);

	height=startheight;

	for(;;){
		printf("%s%d %c  %s%4.1f\n","t=",t,'c',"h=",height);
		t++;
		double way=(g*(double)(t*t))/2;
		height=startheight-way;
		if(height<=0)
			break;
		else
			wait(sec);
	}
	printf("BABAH!");

	int end;
	scanf("%d%",&end);

	return 0;
}