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

	FILE *file;
	char *fname="strings.txt";
	char result_string[120];

	file=fopen(fname,"r");

	if(file == NULL)
	{
		printf("File don't open '%s'",fname);
	}
	else{
		while(!feof(file))
		{
			if(fgets(strings[++strsize],120,file)){
				pointers[psize]=&strings[strsize][0];
				psize++;
			}
		}

		fclose(file);

		bubblesort(pointers,psize);

		file=fopen("NewFile.txt","w");
		for(int i=0;i<psize;i++)
			fprintf(file,"%s\n",pointers[i]);

		fclose(file);

	}

}