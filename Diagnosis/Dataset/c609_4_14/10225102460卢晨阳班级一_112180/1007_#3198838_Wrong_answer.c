#include<stdio.h>
#include<string.h>
#include<stdlib.h> 

typedef struct shuju{
	long long a;//本身数值 
	long long c;
	int b;//1的位数 
}sj;

int cmp(const void*p,const void*q){
	sj*pp=(sj*)p;
	sj*qq=(sj*)q;
	if((pp->b)!=(qq->b))
	return (((pp->b)>(qq->b))?-1:1);
	else
	return (((pp->c)>(qq->c))?1:-1);
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		int n;
		sj s[10001];
		for(int j=0;j<n;j++){
			s[j].a=0;
			s[j].b=0;
		}
		scanf("%d",&n);
		for(int j=0;j<n;j++)
		scanf("%lld",&s[j].a);
		for(int j=0;j<n;j++)
		s[j].c=s[j].a;
		for(int j=0;j<n;j++){
			while(s[j].a!=0){
				s[j].b++;
				s[j].a&=(s[j].a-1);
			}
		}
		qsort(s,n,sizeof(s[0]),cmp);
		printf("case #%d:\n",i);
		for(int j=0;j<n;j++)
		printf("%lld ",s[j].c);
		printf("\n");
	}
	return 0;
 } 