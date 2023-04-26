#include<stdio.h>
#include<stdlib.h>
typedef struct{
	long long int r;
	long long int h;
	long long int ce;
	long long int circular;
}Column;

/*int cmp_r(const void* p1,const void* p2){
	Column* a=(Column*)p1;
	Column* b=(Column*)p2;
	if(b->r>a->r)
		return 1;
	return -1;
}*/
int cmp_max(const void* p1,const void* p2){
	Column* a=(Column*)p1;
	Column* b=(Column*)p2;
	long long a1=a->ce+a->circular;
	long long b1=a->ce+b->circular;	
	if(a1<b1)
		return 1;		
	return -1;
}
int cmp(const void* p1,const void* p2){
	Column* a=(Column*)p1;
	Column* b=(Column*)p2;
	if(a->ce>b->ce)
		return -1;
	if(a->ce<b->ce)
		return 1;
	if(b->r>a->r)
		return 1;
	return -1;
}
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	Column column[n];
	for(int i=0;i<n;i++){
		scanf("%lld %lld",&column[i].r,&column[i].h);
		column[i].ce=2*column[i].r*column[i].h;
		column[i].circular=column[i].r*column[i].r;
	}
	qsort(column,n,sizeof(Column),cmp_max);
	long long int sum=column[0].circular+column[0].ce;
	column[0].circular=0,column[0].ce=0;
	qsort(column,n,sizeof(Column),cmp);	
	for(int i=0;i<m;i++){
		sum+=column[i].ce;
	}
	printf("%lld",sum);
	return 0;
 } 