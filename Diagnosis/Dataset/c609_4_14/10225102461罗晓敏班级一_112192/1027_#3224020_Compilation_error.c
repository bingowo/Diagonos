#include <stdio.h>
#include <stdlib.h>
typedef struct{
	char a[12];
	int score;
}sta;
int cmp(const void* a,const void* b){
	sta *c=(sta*)a,*d=(sta*)b;
	int ret=d->score-c->score;
	if(ret){
		return ret;
	}else{
		return strcmp(c->a,d->a);
	}
}
int main(){
	int t,i;scanf("%d",&t);
	int n,m,g,j,b,c,grade,k;//b是对的题数，c是对的哪道题 
	for(i=0;i<t;i++){
		scanf("%d%d%d",&n,&m,&g);
		int value[5];
		for(j=0;j<m;j++){
			scanf("%d",&value[j]);
		}
		sta* num=(sta*)malloc(n*sizeof(sta));
		for(j=0;j<n;j++){
			scanf("%s%d",num[j].a,&b);
			grade=0;
			for(k=0;k<b;k++){
				scanf("%d",&c);
				grade+=value[c-1];
			}
			if(grade<g){
				j--;
				n--;
			}else{
				num[j]=grade;
			}
		}
		qsort(num,n,sizeof(sta),cmp);
		printf("case #%d:\n%d\n",i,n);
		for(j=0;j<n;j++){
			printf("%s %d\n",num[j].a,num[j].score);
		}
		free(num);
	}
} 