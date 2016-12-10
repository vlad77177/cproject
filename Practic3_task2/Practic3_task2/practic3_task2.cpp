#include <stdio.h>
#include <string.h>

struct WORDS{
	char word[32];
	int leight;
};

int main(){

	char str[120];

	printf("Enter string:\n");
	gets(str);

	WORDS words[64];
	WORDS* start=words;
	int size=0;

	int stringsize=strlen(str);

	bool exit=false;

	for(int i=0;i<stringsize-1;i++){
		if(exit==true)
			break;
		start->leight=0;
		if(str[i]!=' '){
			bool newword=false;
			int j=i;
			int chnumb=0;
			while(newword==false){
				if(str[j]!=' '){
					if(str[j]==0){
						start->word[chnumb]='\0';
						exit=true;
						break;
					}
					start->word[chnumb]=str[j];
					start->leight++;
					chnumb++;
					j++;
				}
				else{
					newword=true;
					start->word[chnumb]='\0';
					size++;
					start++;
					i=j;
				}
			}
		}
	}

	for(int r=0;r<=size;r++)
		printf("%s : %d\n",words[r].word,words[r].leight);

	int end;
	scanf("%d",&end);

}