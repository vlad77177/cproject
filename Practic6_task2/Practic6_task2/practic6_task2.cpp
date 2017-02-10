/* The longest sequence=837799, 524 steps*/
#include <stdio.h>

#define MIN 2
#define MAX 1000000

int Kollatz(long long int n,int step,bool print){
    if(print==true)
        printf("%lli    step=%d\n",n,step);
    if(step==0){
        if(n<MIN || n>MAX)
            return 0;
    }
    if(n==1){
        return step;
    }
    if(n%2==0){
        Kollatz(n/2,step+1,print);
    }
    else{
        Kollatz(3*n+1,step+1,print);
    }
}

int main(){

    printf("1-Printing sequence for the number\n2-Find the longest sequence\n");

    int mode=0;
    scanf("%d",&mode);
    if(mode==1){
        printf("Enter number: ");

        long long int number;
        scanf("%lli",&number);

        int step=Kollatz(number,0,true);

        printf("\nStep=%d",step);
    }
    if(mode==2){
        int maxstep=0;
        int maxnum=0;
        for(int i=MIN;i<=MAX;i++){
            int res=Kollatz((long long int)i,0,false);
            if(res>maxstep){
                maxstep=res;
                maxnum=i;
            }
        }
        printf("Calculated values are from %d to %d, the longest sequence of %d steps for the number %d\n",MIN,MAX,maxstep,maxnum);
    }

    int end;
    scanf("%d",&end);

}