#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <time.h>

struct STRING{
	char str[10][120];
	char *pword[10][10];
	int wordsinstr[10];
	int strsize;
};

void FindWords(STRING &s){
	for(int i=0;i<s.strsize;i++){
		int wordsfind=0;
		bool nextword=true;
		for(int j=0;;j++){
			if(s.str[i][j]=='\0')
				break;
			if(s.str[i][j]!=' ' && nextword==true){
				s.pword[i][wordsfind]=&s.str[i][j];
				wordsfind++;
				nextword=false;
			}
			else if(s.str[i][j]==' ' && nextword==false){
				nextword=true;
			}
		}
		s.wordsinstr[i]=wordsfind;
	}
}

void GetWord(char w[20],char *p){
	int wsize=0;
	while(true){
		if(*p!=' ' && *p!='\0'){
			w[wsize]=*p;
			p++;
			wsize++;
		}
		else{
			if(*p=='\0')
				w[--wsize]='\0';
			else
				w[wsize]='\0';
			return;
		}
	}
}

void RemoveSpaces(char *s){
	for(int i=0;i<strlen(s);i++){
		char *see=s+i;
		if(*see==' '){
			for(int j=i;j<strlen(s);j++){
				char *first=s+j;
				char *second=s+j+1;	
				char a=*first;
				*first=*second;
				*second=a;
			}
			i=0;
		}
	}
}

void RandomMixed(char w[20]){
	int leight=strlen(w);
	if(leight<4)
		return;
	char *nomixed=(char*)calloc(leight-2,sizeof(char));
	//массив символов внутри слова, не перемешанный
	char *mixed=(char*)calloc(leight-2,sizeof(char));
	//массив для перемешанных символов
	for(int i=1;i<leight-1;i++){
		nomixed[i-1]=w[i];
	}
	for(int i=0;i<leight-2;i++){
		int buffsize=leight-2-i;
		//массив ссылок на еще не используемые символы
		char **unusedsymbols=(char**)malloc(buffsize*sizeof(char*));
		for(int j=0,n=0;j<leight-2;j++,n++){
			//записываю в массив только неиспользуемые символы
			if(nomixed[j]!=' ')
				unusedsymbols[n]=&nomixed[j];			
			else
				n--;
		}
		int r=rand()%buffsize;
		//значение mixed[i] - случайный символ, который еще не выбирался
		mixed[i]=*unusedsymbols[r];
		//по ссылке помечаю символ как уже используемый - пробелом
		*unusedsymbols[r]=' ';
		free(unusedsymbols);
	}
	for(int i=0;i<leight-2;i++){
		w[i+1]=mixed[i];
	}
	free(nomixed);
	free(mixed);
}

void MixedPrint(STRING &s){
	for(int i=0;i<s.strsize;i++){
		for(int j=0;j<s.wordsinstr[i];j++){
			char word[20];
			GetWord(word,s.pword[i][j]);
			RandomMixed(word);
			printf("%s ",word);
		}
		printf("\n");
	}
}

int main(){

	SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

	STRING string;
	string.strsize=0;

	int rvalue=(int)time(NULL);
	srand(rvalue);

	FILE *file;
	file=fopen("text.txt","r");

	if(file == NULL)
	{
		printf("Dont open");
	}
	else{
		while(!feof(file))
		{
			if(fgets(string.str[string.strsize],120,file)){
				string.strsize++;
			}
		}
		for(int i=0;i<string.strsize;i++){
			printf("%s\n",string.str[i]);
		}
		printf("* * *\n");
		FindWords(string);
		MixedPrint(string);
	}

	int end;
	scanf("%d",&end);
}