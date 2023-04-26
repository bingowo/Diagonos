#include<stdio.h>
struct data
{
	long long int a;
	int num;
};
int cmp(const void*a,const void *b){
	struct data d1,d2;
	d1=*((struct data*)a);
	d2=*((struct data*)b);
	if(d2.num!=d1.num)
		return d2.num-d1.num;
	else{
		if(d1.a>d2.a)
			return 1;
		else return -1;
	}
}
int main()
{
	int n;
	struct data p[10000];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int k;
		scanf("%d",&k);
		for(int j=0;j<k;j++){
			scanf("%lld",&p[j].a);
			long long int d=1;
			p[j].num=0;
			for(int t=0;t<64;t++){
				if(p[j].a&d)
					p[j].num++;
				d=d<<1;
			}
		}
		qsort(p,k,sizeof(p[0]),cmp);
		printf("case #%d\n",i);
		for(int j=0;j<k;j++){
			printf("%lld ",p[j].a);
		}
		printf("\n");
	}	
	return 0;
 } 