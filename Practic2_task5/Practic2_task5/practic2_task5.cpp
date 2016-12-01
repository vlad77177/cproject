#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

	const int ascii_number_0=48;
	const int ascii_number_9=57;
	const int ascii_latin_A=65;
	const int ascii_latin_Z=90;
	const int ascii_latin_a=97;
	const int ascii_latin_z=122;

	const int passcount=10;
	const int pass_size=8;

	int start_value=time(NULL);
	srand(start_value);

	printf("%s %d %s\n\n","Generate",passcount,"passwords");

	for(int i=0;i<passcount;i++){
		char string[pass_size-1];
		for(int j=0;j<pass_size;j++){
			int choise=1+rand()%3;	//the choice of the ASCII range of characters
			int value;
			switch(choise){
			case 1:{
						value=ascii_number_0+rand() % (ascii_number_9-ascii_number_0);
						break;
				   }
			case 2:{
						value=ascii_latin_A+rand() % (ascii_latin_Z-ascii_latin_A);
						break;
				   }
			case 3:{
						value=ascii_latin_a+rand() % (ascii_latin_z-ascii_latin_a);
						break;
				   }
			}
			string[j]=(char)value;
		}
		for(int l=0;l<pass_size;l++)
			printf("%c",string[l]);
		printf("\n");
	}

	int end;
	scanf("%d",&end);

	return 0;
}