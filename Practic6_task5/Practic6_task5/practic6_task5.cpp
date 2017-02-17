#include <stdio.h>
#include <time.h>

#define MIN 1
#define MAX 40

int fib(int n){
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    else
        return fib(n-1)+fib(n-2);
}

int main(){
    int n=0;
    printf("Enter mode:\n1-you N value\n2-on screen\n3-on file\n");
    int mode=0;
    scanf("%d",&mode);
    if(mode==1)
    {
        while(true){
            printf("Enter N:");
            scanf("%d",&n);
            if(n>=MIN && n<=MAX)
                break;
        }
        int start=clock();
        int res=fib(n);
        int dur=clock()-start;
        printf("%d duration: %d ms",res,dur);
    }
    if(mode==2){
        for(int i=MIN;i<=MAX;i++){
            int start=clock();
            int res=fib(i);
            int dur=clock()-start;
            printf("For N=%d: Result=%d Duration=%d ms\n",i,res,dur);
        }
    }
    if(mode==3){
        FILE *file;
        file=fopen("result.txt","w");
        for(int i=MIN;i<=MAX;i++){
            int start=clock();
            int res=fib(i);
            int dur=clock()-start;
            fprintf(file,"%d %d\n",res,dur);
        }
        fclose(file);
    }
    printf("End!");
    int end;
    scanf("%d",&end);
}