#include<stdio.h>
#include <stdlib.h>
#include <math.h>

int cmp(const void* a, const void* b);
char c;
int main()
{
	scanf("%c",&c);
	int s[100];
	int n=0;
	while(scanf("%d",&s[n]))
		n++;
	qsort(s,n,sizeof(s[0]),cmp);
	int t[100];
	for(int r=0;r<n;r++)
	    t[r]=s[r];
	int cnt=0;
	for(int i=1;i<n;i++)
	{
		if(t[cnt]!=s[i])
		{
			cnt++;
			t[cnt]=s[i];
		}
	}
	for(int j=0;j<cnt;j++)
	    printf("%d ",t[j]);
	printf("%d",t[cnt]);
	return 0;
}

int cmp(const void* a, const void* b)
{
	unsigned *x = (unsigned *)a;
	unsigned *y = (unsigned *)b;
	if(c=='A')
		return *x<*y;
	else
	    return *x>*y;
}