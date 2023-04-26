#include<stdio.h>
#include<stdlib.h>
typedef struct{int n,index;} REC;
int cmp(const void* a,const void* b)
{
	return *(int*)a-*(int*)b;
}
int main()
{
	int m,n,i,j,cnt=0,cnt2=0,flag;scanf("%d",&m);
	int a[m];
	for(i=0;i<m;++i)scanf("%d",&a[i]);
	scanf("%d",&n);
	int b[n];
	for(i=0;i<n;++i)scanf("%d",&b[i]);
	REC c[500];int d[500];
	for(i=0;i<m;++i)
		for(j=0;j<n;++j)
			if(a[i]==b[j])
			{
				c[cnt].n=a[i];
				c[cnt++].index=j;
			}
	for(i=0;i<n;++i)
	{
		flag=1;
		for(j=0;j<cnt;++j)
		{
			if(i==c[j].index)
			{
				flag=0;
				break;
			}
		}
		if(flag)d[cnt2++]=b[i];
	}
	qsort(d,cnt2,sizeof(int),cmp);
	for(i=0;i<cnt;i++)printf("%d ",c[i].n);
	for(i=0;i<cnt2;++i)printf("%d ",d[i]);
	return 0;
}