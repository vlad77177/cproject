#include <stdio.h>
#include <string.h>

void bubblesort(char **p,int size){
	for (int i = 0; i < size - 1; i++){
        bool swapped = false;
        for (int j = 0; j < size - i - 1; j++) {
           if(strlen(p[j])<strlen(p[j+1])){
			   char *a;
			   a=p[j];
			   p[j]=p[j+1];
			   p[j+1]=a;
			   swapped=true;
		   }
        } 
		if(!swapped)
			break;
    }
}


int main(){

	char strings[12][120];
	int strsize=-1;

	char *pointers[12];
	int psize=0;

	printf("Enter string:\n");
	do{
		strsize++;
		gets(strings[strsize]);
		pointers[psize]=&strings[strsize][0];
		psize++;
	}while(strlen(strings[strsize])!=0);

	bubblesort(pointers,psize);

	printf("The rows in descending order:\n\n");
	for(int i=0;i<psize;i++)
		printf("%s\n",pointers[i]);

	int end;
	scanf("%d",&end);

}