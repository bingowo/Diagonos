#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
	char a[11];
	char b[6];
	int c;
	char d[260];
}sta;
char judge[11];
int cmp(const void *a,const void* b){
	sta *c=(sta*)a,*d=(sta*)b;int ret;
	if(judge[6]=='N'){
		return strcmp(c->d,d->d);
	}else if(judge[6]=='S'){
		return (c->c!=d->c)?((c->c)-(d->c)):strcmp(c->d,d->d);
	}else if((ret=strcmp(c->a,d->a))!=0){
		return ret;
	}else if((ret=strcmp(c->b,d->b))!=0){
		return ret;
	}else return strcmp(c->d,d->d);
}
int main(){
	int n,i;
	while(scanf("%d",&n)!=EOF&&n){
		sta* num=(sta*)malloc(n*sizeof(sta));
		for(i=0;i<n;i++){
			scanf("%s%s%d%s",num[i].a,num[i].b,&num[i].c,num[i].d);
		}getchar();gets(judge);
		qsort(num,n,sizeof(sta),cmp);
		for(i=0;i<n;i++){
			printf("%s %s %16d %s\n",num[i].a,num[i].b,num[i].c,num[i].d);
		}
		printf("\n");
		free(num);
	}
	return 0;
} 