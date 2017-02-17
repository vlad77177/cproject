#include <stdio.h>
#include <stdlib.h>

#define MIN 2
#define MAX 40

int fib2(int n,int *R){
    if(n==0){
        R[n]=0;
        return 0;
    }
    if(n==1){
        R[n]=1;
        return 1;
    }
    /*If you want to see a Real Magic, just commentary condition at the bottom and enter a large number*/
    if(R[n-1]!=0)
        return R[n];
    /*Have a Fun!*/
    R[n]=fib2(n-1,R)+fib2(n-2,R);
    return R[n];
}

int fib(int n){
    int *Arr=(int*)calloc(n+1,sizeof(int));
    int r=fib2(n,Arr);
    free(Arr);
    return r;
}

int main(){
    int n=0;
    while(true){
        printf("Enter N:");
        scanf("%d",&n);
        if(n>=MIN && n<=MAX)
            break;
    }   
    int res=fib(n);
    printf("%d\n",res);
    int end;
    scanf("%d",&end);
}