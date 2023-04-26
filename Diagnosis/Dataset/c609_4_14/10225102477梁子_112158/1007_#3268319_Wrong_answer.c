#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
struct data
{
	long long int a;
	int num;
};
int cmp(const void*a,const void *b)
{
	struct data d1,d2;
	d1=*((struct data*)a);
	d2=*((struct data*)b);
	if(d1.num!=d2.num)return d2.num-d1.num;
	else{
		if(d1.a>d2.a)return 1;
		else return -1;
	}
}
int main()
{
	int t,n;
	struct data p[10000];
	scanf("%d",&t);
	int i=0;
	for(;i<t;i++){
		scanf("%d",&n);
		printf("case #%d:\n",i);
		for(;i<n;i++){
			scanf("%lld",&p[i].a);
			p[i].num=0;
			long long d=1;
			int r=0;
			for(;r<64;r++){
				if(p[i].a&d)p[i].num++;
				d=d<<1;
			}
		}
		qsort(p,n,sizeof(p[0]),cmp);
		int j=0;
		for(;j<n;j++)
			printf("%lld",p[j].a);
			printf("\n");
	} 
	return 0;
}