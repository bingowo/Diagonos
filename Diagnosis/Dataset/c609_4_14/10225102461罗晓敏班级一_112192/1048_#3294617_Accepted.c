#include <stdio.h>
#include <stdlib.h>
typedef struct bi{
	int cnt;
	int num[100];
}bigint;
void bigint_addition(bigint* a,bigint* b,bigint* c){
	int i,temp=0;
	for(i=0;i<a->cnt||i<b->cnt;i++){
		c->num[i]=(a->num[i]+b->num[i]+temp)%10;
		temp=(a->num[i]+b->num[i]+temp)/10;
	}
	if(temp){
		c->num[i++]=temp;
		c->cnt=(a->cnt>b->cnt?a->cnt:b->cnt)+1;
		return;
	}
	c->cnt=a->cnt>b->cnt?a->cnt:b->cnt;
}
int main(){
	int t;scanf("%d",&t);
	int i;
	bigint* p=(bigint*)malloc(121*sizeof(bigint));
	p[0].cnt=1;p[0].num[0]=0;
	p[1].cnt=1;p[1].num[0]=1;
	p[2].cnt=1;p[2].num[0]=1;
	for(i=3;i<121;i++){
		bigint_addition(p+i-1,p+i-2,p+i);
	}
	for(i=0;i<t;i++){
		int n;scanf("%d",&n);
		printf("case #%d:\n",i);
		int j;
		for(j=p[n].cnt-1;j>=0;j--){
			printf("%d",p[n].num[j]);	
		}
		printf("\n");
	}
}