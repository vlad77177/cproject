#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct STRING{
	char str[120];
	char *pointers[10];
	int wordcount;
};

void getWords(STRING &s){
	for(int i=0;i<strlen(s.str)-1;i++){
		s.pointers[s.wordcount]=&s.str[i];
		s.wordcount++;
		for(int j=i;;j++){
			if(s.str[j]==' '){
				i=j;
				break;
			}
		}
	}
}

void printWord(STRING &s,int n){
	char *now=s.pointers[n];
	while(true){
		if(*now!=' ' && *now!='\0'){
			printf("%c",*now);
			now++;
		}
		else{
			printf("%c",' ');
			break;
		}
	}
}

void MixingPrint(STRING &s){

	int *nomixednumbers=(int*)malloc(s.wordcount);
	int *mixednumbers=(int*)malloc(s.wordcount);

	for(int i=0;i<s.wordcount;i++){
		nomixednumbers[i]=i;
	}

	int startval=time(NULL);
	srand(startval);

	int *unmixed=(int*)calloc(s.wordcount,sizeof(int));

	for(int i=s.wordcount,n=0;i>0;i--,n++){
		
		for(int j=0,n=0;j<s.wordcount;j++){
			if(nomixednumbers[j]!=-1){
				unmixed[n]=nomixednumbers[j];
				n++;
			}
		}
		int r=rand()%i;
		//printf("%d",r);
		mixednumbers[n]=unmixed[r];
		nomixednumbers[r]=-1;
	}

	free(unmixed);
	
	for(int i=0;i<s.wordcount;i++){
		printWord(s,mixednumbers[i]);
	}
}

int main(){

	STRING string;
	string.wordcount=0;
	printf("Enter string:\n");
	gets(string.str);

	getWords(string);
	MixingPrint(string);

	int end;
	scanf("%d",&end);
}