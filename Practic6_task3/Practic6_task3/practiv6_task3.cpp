#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct STRING{
    char *str;
    char *end;
    int size;
};

void convertToString(STRING *s,int n,int abit){
    s->str=(char*)realloc(s->str,(s->size+1)*sizeof(char*));
    char *pnow=s->end;
    if(abit==0)
        return;
    int rest=n%abit;
    if(rest!=0){
        *s->end=(char)rest+48;
        s->end++;
        s->size++;
        convertToString(s,n/10,abit);
    }
    else{
        s->end--;
        char *pend=s->end;
        for(int i=0;i<s->size/2+1;i++){
            char a=s->str[i];
            s->str[i]=*pend;
            *pend=a;
            pend--;
        }
        s->str[s->size]='\0';
        return;
    }
}

int main(){
    printf("Enter number: ");

    int n=0;
    scanf("%d",&n);

    STRING string;
    string.str=(char*)malloc(sizeof(char*));
    string.end=string.str;
    string.size=0;

    convertToString(&string,n,10);
    printf("String: %s\n",string.str);
    
    int end;
    scanf("%d",&end);
}