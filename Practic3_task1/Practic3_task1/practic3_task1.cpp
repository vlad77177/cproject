#include <stdio.h>
#include <string.h>

int main(){

	char str[120];

	printf("Enter string:\n");
	gets(str);

	int words=0;

	for(int i=0;i<strlen(str)-1;i++){
		if(str[i]!=' '){
			bool newword=false;
			int j=i;
			while(newword==false){
				if(str[j]!=' ')
					j++;
				else{
					newword=true;
					words++;
					i=j+1;
				}
			}
		}
	}

	printf("%s %d\n","Words in string:",words);

	int end;
	scanf("%d",&end);

}