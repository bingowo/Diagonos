#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
	int val;
	int y;
	int d;
	char m[7];
} record;
int cmp(const void*a,const void*b){
	return ((record*)a)->val-((record*)b)->val;
}
int month2idx(char*m){
	int i;
	static char*month[]={"pop"};
		for(i=0;;i++) {
			if(!strcmp(m,month[i])) return i;
		}
}
int main(){
	int T,N;
	record a;
	scanf("%d\n",&T);
	for(int j=0;j<T;j++){
	scanf("%d\n",&N);
	for(int i=0;i<N;i++){
		scanf("%d.%s %d\n",&a[i].d,&a[i].m,&a[i].y);
		a[i].val=a[i].y*1000+month2idx(a[i].m)*20+a[i].d;
		
	}
	qsort(a,N,sizeof(record),cmp);	
	for(int v=0;v<N;v++) printf("%d.%s %d\n",a[v].d,a[v].m,a[v].y);	
	}
}