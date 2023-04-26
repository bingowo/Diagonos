#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int n;
struct node
{
	char s[20];
	long long val;
}a[10010];
long long cal(char s[])
{
	int table[300];
	long long res = 0;
	int len = strlen(s);
	int i;
	int cnt = 0;
	memset(table,-1,sizeof(table));
	for(i=0;i<len;i++)
	{
		if(table[s[i]]==-1)
		{
			if(cnt==0) table[s[i]] = 1;
			else if(cnt==1) table[s[i]] = 0;
			else table[s[i]] = cnt;
			cnt++;
		}
	}
	if(cnt==1) cnt = 2;
	for(i=0;i<len;i++)
		res = res*cnt + table[s[i]];
	return res;
}
int mycmp(const void* aa,const void* bb)
{
	struct node a = *(struct node*)aa;
	struct node b = *(struct node*)bb;
	if(a.val==b.val) return strcmp(a.s,b.s);
	else
	{
		if(a.val <= b.val) return -1;
		else return 1;
	}
}
int main(void)
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s",a[i].s);
		a[i].val = cal(a[i].s);
	}
	qsort(a,n,sizeof(a[0]),mycmp);
	for(int i=0;i<n;i++) printf("%s\n",a[i].s);
	return 0;
}