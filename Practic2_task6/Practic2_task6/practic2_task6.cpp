#include <stdio.h>
#include <string.h>

int main(){

	char string[80];

	gets(string);

	for(int i=0;i<strlen(string);i++){

		if(string[0]==' '){
			for(int j=0;j<strlen(string);j++){
				string[j]=string[j+1];
			}
			i=0;
			continue;
		}	
		if(string[strlen(string)-1]==' '){
			string[strlen(string)-1]='\0';
			i=0;
			continue;
		}
		if(string[i]==' ' && string[i+1]==' '){
			for(int j=i;j<strlen(string);j++){
				string[j+1]=string[j+2];
			}
			i=0;
			continue;
		}
	}

	printf("%s",string);

	int end;
	scanf("%d",&end);

	return 0;
}