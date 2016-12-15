/*This program - modification of practic3_task2*/
#include <stdio.h>
#include <string.h>

struct WORDS{
	char word[32];
};

int main(){

	char str[120];
	int number;

	printf("Enter string:\n");
	gets(str);
	printf("Enter number of word:\n");
	scanf("%d",&number);

	WORDS words[64];
	WORDS* start=words;
	int size=0;

	int stringsize=strlen(str);

	bool exit=false;

	for(int i=0;i<stringsize-1;i++){
		if(exit==true)
			break;
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

	if(number<=size)
		printf("%s %d : %s\n","Word number",number,words[number-1].word);
	else
		printf("%s %d %s\n","Error! The entered phrase is only", size+1, "words");

	int end;
	scanf("%d",&end);

}