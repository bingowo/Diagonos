#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char sortofmonth[19][7]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol",
"chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
typedef struct{
	int day;
	char month[7];
	int year;
}sta;
int cmp(const void* a,const void* b){
	int x,y;sta *c=(sta*)a,*d=(sta*)b;
	int e=c->year,f=d->year;char *g=c->month,*h=d->month;int i=c->day,j=c->day;
	for(x=0;x<19;x++) if(strcmp(g,sortofmonth[x])==0) break;
	for(y=0;y<19;y++) if(strcmp(h,sortofmonth[y])==0) break;
	return (e!=f)?e-f:((x!=y)?x-y:i-j);
}
int main(){
	int t,i;scanf("%d",&t);
	int n,j;
	for(i=0;i<t;i++){
		scanf("%d",&n);
		sta* num=(sta*)malloc(n*sizeof(sta));
		for(j=0;j<n;j++){
			scanf("%d. %s %d",&num[j].day,&num[j].month,&num[j].year);
		}
		qsort(num,n,sizeof(sta),cmp);
		for(j=0;j<n;j++){
			printf("%d. %s %d\n",num[j].day,num[j].month,num[j].year);
		}
		free(num);
	}
}