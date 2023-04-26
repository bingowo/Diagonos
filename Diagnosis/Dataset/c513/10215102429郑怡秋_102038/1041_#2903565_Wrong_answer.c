#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>
int cmp(const void*a,const void*b)
{
	int*p1=(int *)a;int*p2=(int*)b;
	return *p2-*p1;
}
int main()
{
	char s[60];
	scanf("%s",s);
	int cnt[50]={0};
	int j=0;
	int l=strlen(s);
	for(int i=0;i<l;i++)
	{
		if(s[i]!=s[i+1]) cnt[j]++;
		else j++; 
	}
	qsort(cnt,j,sizeof(int),cmp);
	printf("%d\n",cnt[0]+1);
	return 0;
}