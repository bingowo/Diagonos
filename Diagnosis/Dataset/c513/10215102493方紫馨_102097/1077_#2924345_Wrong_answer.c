#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	int n;
	int order;
}p;
int cmp(const void* p1,const void* p2){
	p* a = (p*)p1;
	p* b = (p*)p2;
	if(a->order==0&&b->order==0)
		return a->n-b->n;
	if(a->order==0)
		return 1;
	if(b->order==0)
		return -1;
	return a->order-b->order;
}
	
int main()
{
	int m,n;
	scanf("%d",&m);
	int a[m];
	int num[1010];
	memset(num,0,1010);
	for(int i=0;i<m;i++){
		scanf("%d",&a[i]);
		num[a[i]]=i+1;
	}
	scanf("%d",&n);
	p b[n];
	for(int i=0;i<n;i++){
		scanf("%d",&b[i].n);
		b[i].order=num[b[i].n];
	}
	qsort(b,n,sizeof(p),cmp);
	for(int i=0;i<n-1;i++)
		printf("%d ",b[i].n);
	printf("%d",b[n-1].n);
	return 0;
 } 