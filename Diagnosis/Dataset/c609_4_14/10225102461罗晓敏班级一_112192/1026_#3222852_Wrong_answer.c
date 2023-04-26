#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
	char s[21];
	int cnt;
}sta;
int f1(char* num){
	int ret=1;
	char n[21];n[0]=num[0];n[1]='\0';
	int k=1,i;
	for(i=1;num[i];i++){
		if(strchr(n,num[i])==0){
			ret++;
			n[k]=num[i];
			n[k+1]='\0';
			k++;
		}
	}
	return ret;
}
int f2(const void* a,const void *b){
	sta* c=(sta*)a,*d=(sta*)b;
	int e=d->cnt-c->cnt;
	e?e:strcmp(c->s,d->s);
}
int main(){
	int t,i;scanf("%d",&t);
	int n,j,k;
	for(i=0;i<t;i++){
		scanf("%d",&n);
		sta* num=(sta*)malloc(n*sizeof(sta));
		for(j=0;j<n;j++){
			scanf("%s",num[j].s);
			num[j].cnt=f1(num[j].s);
		}
		qsort(num,n,sizeof(sta),f2);
		printf("case #%d:\n",i);
		for(j=0;j<n;j++){
			printf("%s\n",num[j].s);
		}
		free(num);
	}
}