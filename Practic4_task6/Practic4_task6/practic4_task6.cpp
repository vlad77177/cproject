#include <stdio.h>
#include <stdlib.h>

struct MEMBER{
	char name[20];
	int age;
};

struct FAMILY{
	int count;
	int sizenow;
	MEMBER *young;
	MEMBER *old;
	MEMBER members[10];
};

void FindYoungOld(FAMILY &f){
	if(f.sizenow>2){
		for(int i=0;i<f.sizenow;i++){
			if(f.members[i].age<f.young->age){
				f.young=&f.members[i];
			}
			if(f.members[i].age>f.old->age){
				f.old=&f.members[i];
			}
		}
	}
	else if(f.sizenow==2){
		if(f.members[0].age<f.members[1].age){
			f.young=&f.members[0];
			f.old=&f.members[1];
		}
		else{
			f.young=&f.members[1];
			f.old=&f.members[0];
		}
	}
	else{
		f.young=&f.members[0];
		f.old=&f.members[0];
	}
}

int main(){

	FAMILY family;
	family.count=0;
	family.sizenow=0;
	printf("Enter family size:\n");
	scanf("%d",&family.count);

	for(int i=0;i<family.count;i++){
		printf("%s %d %s\n","Enter member",i+1,"name:");
		scanf("%s",&family.members[i].name);
		printf("%s %d %s\n","Enter member",i+1,"age:");
		scanf("%d",&family.members[i].age);
		family.sizenow++;
		FindYoungOld(family);
	}

	printf("%s %s %d\n","Young:",family.young->name,family.young->age);
	printf("%s %s %d\n","Old:",family.old->name,family.old->age);

	int end;
	scanf("%d",&end);
}