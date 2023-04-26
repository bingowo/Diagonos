#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
struct data{
	char id[12];
	int A,C,M,E;
};
int cmpA(const void* p1,const void* p2){
	struct data* a = (struct data*)p1;
	struct data* b = (struct data*)p2;
	if(a->A!=b->A)
		return b->A-a->A;
	else
		return strcmp(a->id,b->id);		
}
int cmpC(const void* p1,const void* p2){
	struct data* a = (struct data*)p1;
	struct data* b = (struct data*)p2;
	if(a->C!=b->C)
		return b->C-a->C;
	else
		return strcmp(a->id,b->id);		
}
int cmpM(const void* p1,const void* p2){
	struct data* a = (struct data*)p1;
	struct data* b = (struct data*)p2;
	if(a->M!=b->M)
		return b->M-a->M;
	else
		return strcmp(a->id,b->id);		
}
int cmpE(const void* p1,const void* p2){
	struct data* a = (struct data*)p1;
	struct data* b = (struct data*)p2;
	if(a->E!=b->E)
		return b->E-a->E;
	else
		return strcmp(a->id,b->id);		
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int j=0;j<T;j++){
		printf("case #%d:\n",j);
		int N;
		scanf("%d",&N);
		struct data stu[100];
		int k=0;
		for(;k<N;k++){
			scanf("%s%d%d%d",stu[k].id,&stu[k].C,&stu[k].M,&stu[k].E);
			stu[k].A = (int)((stu[k].C+stu[k].M+stu[k].E)/3+0.5);
		}
		qsort(stu,k,sizeof(stu[0]),cmpA);
		printf("A:\n");
		for(int i=0;i<k;i++){
			if(stu[i].A==stu[0].A)
				printf("%s\n",stu[i].id);
			else
				break;
		}
		
		qsort(stu,k,sizeof(stu[0]),cmpC);
		printf("C:\n");
		for(int i=0;i<k;i++){
			if(stu[i].C==stu[0].C)
				printf("%s\n",stu[i].id);
			else
				break;
		}
		
		qsort(stu,k,sizeof(stu[0]),cmpM);
		printf("M:\n");
		for(int i=0;i<k;i++){
			if(stu[i].M==stu[0].M)
				printf("%s\n",stu[i].id);
			else
				break;
		}
		
		qsort(stu,k,sizeof(stu[0]),cmpE);
		printf("E:\n");
		for(int i=0;i<k;i++){
			if(stu[i].E==stu[0].E)
				printf("%s\n",stu[i].id);
			else 
				break;
		}
	}
		
	return 0;
}