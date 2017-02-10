#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 27 //27
#define MIN 6
#define MAX 21

struct FRACTAL{
    bool pole[SIZE][SIZE];
};

void wait(int ms){
	int c=clock()+ms;
	while(clock()<c);
}

void Erase(FRACTAL *f){
    for(int x=0;x<SIZE;x++){
        for(int y=0;y<SIZE;y++){
            f->pole[x][y]=false;
        }
    }
}

void DrawSnowflake(int x,int y,int start_distance,FRACTAL *f,int deep){
    f->pole[x][y]=true;
    if(start_distance>1){
        f->pole[x+1][y]=true;
        f->pole[x-1][y]=true;
        f->pole[x][y+1]=true;
        f->pole[x][y-1]=true;
    }
    if(start_distance>0){
        int newsize=start_distance/2-1;
        DrawSnowflake(x+newsize,y,newsize,f,deep+1);
        DrawSnowflake(x-newsize,y,newsize,f,deep+1);
        DrawSnowflake(x,y+newsize,newsize,f,deep+1);
        DrawSnowflake(x,y-newsize,newsize,f,deep+1);
        DrawSnowflake(x,y,newsize,f,deep);
    }
    else{
        return;
    }
}

void Print(FRACTAL *f){
    for(int x=0;x<SIZE;x++){
        for(int y=0;y<SIZE;y++){
            if(f->pole[x][y]==true)
                printf("%c ",'*');
            else
                printf("%c ",' ');
        }
        printf("\n");
    }
}

int main(){

    int sval=(int)time(NULL);
    srand(sval);

    FRACTAL f;

    for(int i=0;i<100;i++){
        int start=MIN+rand()%(MAX-MIN);
        Erase(&f);
        DrawSnowflake(SIZE/2,SIZE/2,start,&f,1);
        Print(&f);
        wait(5000);
        system("cls");
    }

    int end;
    scanf("%d",&end);

}