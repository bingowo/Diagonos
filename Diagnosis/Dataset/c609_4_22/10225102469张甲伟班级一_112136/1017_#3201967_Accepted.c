#include <stdio.h>
#include<stdlib.h>
int T,a[1000],book[1000];
char p,c;
int cmp1(const void *e1,const void *e2)
{
	return *(int*)e1-*(int*)e2;
}
int cmp2(const void *e1,const void *e2)
{
	return *(int*)e2-*(int*)e1;
}
int main()
{
	scanf("%c",&p);
	int i=0;
	while(scanf("%d",&a[i++])==1)
	{
		c=getchar();
		if(book[a[i-1]]==0)
		{
			book[a[i-1]]=1;
		}
		else
			i--;
	}
	i--;
	if(p=='A')
		qsort(a,i,sizeof(a[0]),cmp1);
	if(p=='D')
		qsort(a,i,sizeof(a[0]),cmp2);
	for(int j=0;j<i;j++)
		printf("%d ",a[j]);
	return 0;
}