#include <stdio.h>
#include <string.h>

#define ASCIIA 65
#define ASCIIZ 90
#define ASCIIREGCONST 32

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

bool IsPalindrom(char s[]){

	char *first=s;
	char *last=first+strlen(s)-1;

	int iteration=0;

	while((first!=last) && (iteration<(int)(strlen(s)/2))){

		if((int)*first>=ASCIIA && (int)*first<=ASCIIZ){
			if(!((int)*first==(int)*last || (int)*first==(int)*last-ASCIIREGCONST)){
				return false;
			}
		}
		else if((int)*first>=ASCIIA+ASCIIREGCONST && (int)*first<=ASCIIZ+ASCIIREGCONST){
			if(!((int)*first==(int)*last || (int)*first==(int)*last+ASCIIREGCONST)){
				return false;
			}
		}
		else if(*first!=*last)
			return false;
		first++;
		last--;
		iteration++;
	}

	return true;
}

int main(){

	char string[120];

	printf("Enter string: \n");

	gets(string);

	bool registr=false;

	RemoveSpaces(string);

	bool res=IsPalindrom(string);

	if(res)
		printf("This palindrom");
	else
		printf("Not palindrom");

	int end;
	scanf("%d",&end);
}