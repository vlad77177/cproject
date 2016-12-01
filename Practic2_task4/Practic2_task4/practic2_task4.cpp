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

	const int maxleight=10;

	char string[maxleight-1];

	int start_value=time(NULL);
	srand(start_value);

	for(int i=0;i<maxleight;i++){
	
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
		string[i]=(char)value;
	}

	printf("Ungrouped string:\n");

	for(int j=0;j<maxleight;j++){
		printf("%c",string[j]);
	}

	printf("\nGrouped string:\n");

	//next - a grouping algorithm

	for(int k=0;k<maxleight-1;k++){
		int ascii_symbol_number=(int)string[k];
		if((ascii_symbol_number>=ascii_number_0) && (ascii_symbol_number<=ascii_number_9)){
			for(int l=k+1;l<maxleight;l++){
				int ascii_symbol_latin=(int)string[l];
				if((ascii_symbol_latin<ascii_number_0) || (ascii_symbol_latin>ascii_number_9)){
					int a=string[k];
					string[k]=string[l];
					string[l]=a;
				}
			}
		}
	}

	for(int j=0;j<maxleight;j++){
		printf("%c",string[j]);
	}

	int end;
	scanf("%d",&end);

}