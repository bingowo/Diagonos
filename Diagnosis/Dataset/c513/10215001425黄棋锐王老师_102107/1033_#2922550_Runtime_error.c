#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
struct maya{
	int val;//记录这一天的总日期 
	int d;
	int y;
	char mo[8];
};
int month_index(char*m){
	static char* month[]={"pop","no","zip","zotz",
	"tzec","xul","yoxkin","mol","chen","yax",
	"zac","ceh","mac","kankin","muan","pax",
	"koyab","cumhu","uayet"};
	int i;
	for(i=0;;i++){
		if(strcmp(m,month[i])==0) return i;
	}
}
int cmp(const void*a,const void*b){
	struct maya *aa=(struct maya*)a;
	struct maya *bb=(struct maya*)b;
	return aa->val-bb->val; 
}
int main(){
	  int i,T,N;
	  scanf("%d",&T);
	  for(i=0;i<T;i++){
	  	struct maya a[10002];
	  	scanf("%d",&N);
	  	int j;
	  	for(j=0;j<N;j++){ 
	  	scanf("%d.%s %d\n",&a[j].d,a[j].mo,a[j].y);
	  	a[j].val=a[j].d+month_index(a[j].mo)*20+a[j].y*1000;
		  }
		  qsort(a,N,sizeof(struct maya),cmp);
		printf("case #%d:\n",i);
		for(j=0;j<N;j++){
			printf("%d.%s %d\n",a[j].d,a[j].mo,a[j].y);
		}
	  } 
		return 0;
}