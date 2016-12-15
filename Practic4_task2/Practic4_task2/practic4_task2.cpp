#include <stdio.h>
#include <string.h>

int main(){

	char string[120];
	char *pointers[32];
	int psize=0;

	printf("Enter string: \n");
	gets(string);

	int i=0;

	for(i;i<strlen(string)-1;i++){
		pointers[psize]=&string[i];
		psize++;
		for(int j=i;;j++){
			if(string[j]==' '){
				i=j;
				break;
			}
		}
	}

	for(int j=psize-1;j>=0;j--){
		for(int s=0;s<=strlen(pointers[j]);s++){
			if(pointers[j][s]!=' ')
				printf("%c",pointers[j][s]);
			else
			{
				printf(" ");
				break;
			}
		}
	}

	int end;
	scanf("%d",&end);
}