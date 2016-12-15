#include <stdio.h>
#include <string.h>

struct  SEQUENCE{
	char ch;
	int leight;
};

int main(){

	char str[120];

	printf("Entes symbol's:\n");
	gets(str);

	printf("%s\n",str);

	SEQUENCE seq={' ',0};

	int i=0;

	for(i;i<strlen(str);){
		int localch=str[i];
		int k=i;
		int localsize=1;
		for(k;;k++){
			if(str[k+1]==localch)
				localsize++;
			else{
				if(seq.leight<localsize){
					seq.ch=localch;
					seq.leight=localsize;
				}
				i=k+1;
				break;
			}
		}
	}

	printf("The maximum sequence: ");
	for(int g=0;g<seq.leight;g++){
		printf("%c",seq.ch);
	}
	printf(" : %s=%d\n","leight",seq.leight);

	int end;
	scanf("%d",&end);


}