#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b)
{
	int p,q;
	p=*(int*)a;q=*(int*)b;
	return p-q;
}

int main()
{
	int m,i;
	int a[501],b[501];
	scanf("%d",&m);
	for(i=0;i<m;i++) scanf("%d",&a[i]);
	int n;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&b[i]);
	int res[500],j,rek[500],k=0,p=0;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(b[j]==a[i]){
				res[k++]=a[i];
			}
		}
	}
	int e=0;


	for(j=0;j<n;j++)
	{
		//printf("o2=%d\n",res[0]);
		for(i=0;i<m;i++)
			if(b[j]!=a[i]) e++;
		if(e==m) rek[p++]=b[j];
		e=0;
	}
	//printf("oo=%d\n",res[0]);
	int k2=k,p2=0;
	qsort(rek,p,sizeof(rek[0]),cmp);
	for(k2;k2<k+p;k2++) res[k2]=rek[p2++];
	for(p2=0;p2<k+p;p2++) printf("%d ",res[p2]);
	return 0;
	
}