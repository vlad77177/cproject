#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Split(char *s,int position){

	int a=s[position];
	s[position]=' ';

	for(int i=strlen(s);i>position;i--){
		int a=s[i];
		s[i+1]=a;
	}

	s[position+1]=a;

}

void CheckStr(char *string,int maxbit){

	bool broken=false;

	for(int i=0;i<strlen(string);i++){
		if(string[i]==0)
			break;
		if(string[i]!=' '){
			int bit=0;
			int j=i;
			for(;;j++,bit++){
				if(string[j]==' ' || string[j]==0){
					break;
				}
			}
			if(bit>maxbit){
				int pos=j-(bit/2);
				Split(string,pos);
				broken=true;
			}
		}
	}
	if(broken==true)
		printf("%s\n%s\n","A long sequence of digits in the string were broken, the result is:",string);
}


int main(){

	const int ascii_number_0=48;
	const int ascii_number_9=57;

	const int maxbit=5;
	const int maxstrleight=120;

	char strnumbers[maxstrleight];

	bool straccept=true;

	do{

	printf("Enter string of numbers\n");
	gets(strnumbers);

		for(int i=0;i<strlen(strnumbers);i++){
			int ascii=(int)strnumbers[i];
			if((ascii>ascii_number_9) || (ascii<ascii_number_0))
				if((char)ascii!=' ')
					straccept=false;
		}
	}while(straccept==false);

	CheckStr(strnumbers,maxbit);

	int summ=0;

	for(int i=0;i<strlen(strnumbers);i++){
		if(strnumbers[i]!=' '){
			char row[maxbit];
			int rowsize=0;
			int j=i;
			for(;;j++){
				if(strnumbers[j]==' ' || strnumbers[j]==0)
					break;
				else{
					row[rowsize]=strnumbers[j];
					rowsize++;
				}
			}
			row[rowsize]='\0';
			summ+=atoi(row);

			i=j;
		}
	}

	printf("%d\n",summ);

	int end;
	scanf("%d",&end);

}