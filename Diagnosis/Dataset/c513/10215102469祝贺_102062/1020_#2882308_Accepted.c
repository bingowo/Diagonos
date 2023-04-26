#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct {
	char date[11];
	char time[6];
	char size[15];
	char name[130];
} inf;
int n;char order[15];
int cmpn(const void*a, const void*b){
	inf *x=(inf*)a,*y=(inf*)b;
	int ans=strcmp(x->name,y->name)<0?-1:1;
	return ans;
}
int cmpt(const void*a, const void*b){
	inf *x=(inf*)a,*y=(inf*)b;
	int ans,a1=strcmp(x->date,y->date),a2=strcmp(x->time,y->time);
	if (a1!=0)
		ans=a1<0?-1:1;
	else if(a2!=0)
		ans=a2<0?-1:1;
	else
		ans=cmpn(a,b);
	return ans;
}
int cmps(const void*a, const void*b){
	inf *x=(inf*)a,*y=(inf*)b;
	int ans,a1=strlen(x->size),a2=strlen(y->size),a3=strcmp(x->size,y->size);
	if(a1!=a2)
		ans=a1<a2?-1:1;
	else if(a3!=0)
		ans=a3<0?-1:1;
	else 
	ans=cmpn(a,b);
	return ans;
}
int main(){
	while(1){
		scanf("%d",&n);
		if(n==0)break;
		inf file[n];
		for(int i=0;i<n;i++){
			scanf("%s%s%s",&file[i].date,&file[i].time,
				&file[i].size);
			fgets(file[i].name,130,stdin);
		}
		scanf("%*s%s",order);
		switch(order[1]){
			case('N'):{
				qsort(file,n,sizeof(inf),cmpn);
				break;
			}
			case('S'):{
				qsort(file,n,sizeof(inf),cmps);
				break;
			}
			case('T'):{
				qsort(file,n,sizeof(inf),cmpt);
				break;
			}
		}
		for(int i=0;i<n;i++)
		{
			printf("%s %s %16s%s",file[i].date,file[i].time,
				file[i].size,file[i].name);
		}
		printf("\n");
	}

	return 0;
}