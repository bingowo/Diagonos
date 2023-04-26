#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
typedef struct record{
	int val;//表示日期大小
	int y;
	int d;
	char m[7]; 
} Record;
int month2idx(char *m){
	int i;
	static char* month[]={"pop","o","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
	for(i=0;;i++){
		if(!strcmp(m,month[i]))return i;
	}
}
int cmp(const void *a,const void*b){
	return ((Record*)a)->val-((Record*)b)->val;
}
int main(){
	long long T,N,cnt=0;
	scanf("%lld",&T);
	
	while(T){
		scanf("%lld",&N);
		Record a[1000001];
		for(int i=0;i<N;i++){
			scanf("%d. %s %d",&a[i].d,&a[i].m,&a[i].y);
			a[i].val=a[i].y*1000+month2idx(a[i].m)*20+a[i].d;
		}
		qsort(a,N,sizeof(Record),cmp);
		printf("case #%d:\n",cnt);
		for (int j=0;j<N;j++){
			printf("%d. %s %d\n",a[j].d,a[j].m,a[j].y);
		}
		
	T--;
	cnt++;	
	}
	return 0;
}