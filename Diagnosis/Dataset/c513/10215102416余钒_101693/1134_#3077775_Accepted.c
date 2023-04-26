#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LL long long
int T,n; 
int num[105];
struct node{
	char name[20];
	int C,E,M,A;
}stu[105];
int cmp(const void*a,const void*b){
	return strcmp(((struct node*)a)->name,((struct node*)b)->name);
}
int main() {
	scanf("%d",&T);
	for(int c=0;c<T;c++){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%s%d%d%d",stu[i].name,&stu[i].C,&stu[i].E,&stu[i].M);
			stu[i].A=stu[i].C+stu[i].E+stu[i].M;
			if(stu[i].A%3>1) stu[i].A/=3,stu[i].A++;
			else stu[i].A/=3;
		}
		qsort(stu+1,n,sizeof(struct node),cmp);
		printf("case #%d:\n",c);
		int mx=0,top=0;
		for(int i=1;i<=n;i++){
			if(stu[i].A>mx) num[top=1]=i,mx=stu[i].A;
			else if(stu[i].A==mx) num[++top]=i;
		}
		printf("A:\n");
		for(int i=1;i<=top;i++) printf("%s\n",stu[num[i]].name);
		mx=0,top=0;
		for(int i=1;i<=n;i++){
			if(stu[i].C>mx) num[top=1]=i,mx=stu[i].C;
			else if(stu[i].C==mx) num[++top]=i;
		}
		printf("C:\n");
		for(int i=1;i<=top;i++) printf("%s\n",stu[num[i]].name);
		mx=0,top=0;
		for(int i=1;i<=n;i++){
			if(stu[i].E>mx) num[top=1]=i,mx=stu[i].E;
			else if(stu[i].E==mx) num[++top]=i;
		}
		printf("M:\n");
		for(int i=1;i<=top;i++) printf("%s\n",stu[num[i]].name);
		mx=0,top=0;
		for(int i=1;i<=n;i++){
			if(stu[i].M>mx) num[top=1]=i,mx=stu[i].M;
			else if(stu[i].M==mx) num[++top]=i;
		}
		printf("E:\n");
		for(int i=1;i<=top;i++) printf("%s\n",stu[num[i]].name);
	}
	return 0;
}