#include <stdio.h>
#include <string.h>

struct TABLECELL{
	char ch;
	int frequency;
};

int main(){

	printf("Enter string:\n");

	char string[120];

	scanf("%s",string);

	TABLECELL firstcell;
	TABLECELL* start=&firstcell;
	int tablesize=0;

	int size=strlen(string);

	for(int i=0;i<size;i++){
		TABLECELL* pnow=start;
		bool newch=true;
		for(int j=0;j<tablesize;j++){
			char comp=pnow->ch;
			if(string[i]==comp){
				pnow->frequency++;
				newch=false;
			}
			pnow++;
		}
		if(newch==true){
			pnow=start;
			for(int y=0;y<tablesize;y++,pnow++);
			pnow->ch=string[i];
			pnow->frequency=1;
			tablesize++;
		}
	}

	for(int k=0;k<tablesize;k++){
		printf("%c : %d\n",start->ch,start->frequency);
		start++;
	}

	int end;
	scanf("%d",&end);

}