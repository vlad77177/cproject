#include <stdio.h>

#define SIZE 27
#define START 20

void Erase(bool pole[SIZE][SIZE]){
    for(int x=0;x<SIZE;x++){
        for(int y=0;y<SIZE;y++){
            pole[x][y]=false;
        }
    }
}

void DrawSnowflake(int x,int y,int start_distance,bool pole[SIZE][SIZE]){
    pole[x][y]=true;
    pole[x+1][y]=true;
    pole[x-1][y]=true;
    pole[x][y+1]=true;
    pole[x][y-1]=true;
    if(start_distance>0){
        int newsize=start_distance/2-1;
        DrawSnowflake(x+newsize,y,newsize,pole);
        DrawSnowflake(x-newsize,y,newsize,pole);
        DrawSnowflake(x,y+newsize,newsize,pole);
        DrawSnowflake(x,y-newsize,newsize,pole);
        DrawSnowflake(x,y,newsize,pole);
    }
    else{
        return;
    }
}

void Print(bool pole[SIZE][SIZE]){
    for(int x=0;x<SIZE;x++){
        for(int y=0;y<SIZE;y++){
            if(pole[x][y]==true)
                printf("%c ",'*');
            else
                printf("%c ",' ');
        }
        printf("\n");
    }
}

int main(){

    bool pole[SIZE][SIZE];
    Erase(pole);
    DrawSnowflake(SIZE/2,SIZE/2,START,pole);
    Print(pole);

    int end;
    scanf("%d",&end);

}