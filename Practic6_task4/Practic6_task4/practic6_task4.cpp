#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

int addTraditional(int *a,int size){
    long long int summ=0;
    for(int i=0;i<size;i++){
        summ+=a[i];
    }
    return summ;
}

int addRecursively(int *a,int size,int summ,int deep){
    if(deep<size){
        summ+=a[deep];
        addRecursively(a,size,summ,deep+1);
    }
    else
        return summ;
}

int main(){

    int rval=(int)time(NULL);
    srand(rval);

    printf("Enter the power of two:");
    int power=0;
    scanf("%d",&power);

    int size=(int)pow(2.0,power);
    int *arr=(int*)malloc(size*sizeof(int));

    printf("The array size %d generated:\n",size);

    for(int i=0;i<size;i++){
        int r=rand()%10;
        arr[i]=r;
    }

    printf("\n\n");

    int start=clock();
    int result=addTraditional(arr,size);
    int dur=clock()-start;

    printf("Added Traditional: summ=%d duration=%d ms\n",result,dur);

    start=clock();
    result=addRecursively(arr,size,0,0);
    dur=clock()-start;

    printf("Added Recursively: summ=%d duration=%d ms\n",result,dur);

    int end;
    scanf("%d",&end);
}