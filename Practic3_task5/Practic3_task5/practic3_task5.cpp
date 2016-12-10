#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1
#define MIN 2

int findmaxmin(int a[],int size,int mode){

	int value=0;
	int number=0;
	for(int i=0;i<size;i++){
		if(i==0){
			value=a[i];
			continue;
		}
		switch(mode){
			case 1:{
						if(a[i]>value){
							value=a[i];
							number=i;
						}
						break;
				   }
			case 2:{
						if(a[i]<value){
							value=a[i];
							number=i;
						}
						break;
				   }
		}
	}
	return number;
}

int summa(int a[],int first,int second){
	int s=0;
	for(int i=first+1;i<second;i++){
		s+=a[i];
	}
	return s;
}

int main(){

	int size=0;

	printf("Enter the size of the array: \n");

	scanf("%d",&size);

	int arr[64];

	int start_value=time(NULL);
	srand(start_value);

	for(int i=0;i<size;i++){
		arr[i]=-100+rand()%(100-(-100));
	}

	for(int i=0;i<size;i++){
		printf("%d ",arr[i]);
	}

	int minimum=findmaxmin(arr,size,MIN);
	int maximum=findmaxmin(arr,size,MAX);

	printf("\n%s %d\n%s %d\n","Minimum:",arr[minimum],"Maximum:",arr[maximum]);
	
	int summ=0;

	if(minimum<maximum)
		summ=summa(arr,minimum,maximum);
	else
		summ=summa(arr,maximum,minimum);

	printf("%s %d\n","Summa:",summ);

	int end;
	scanf("%d",&end);
}