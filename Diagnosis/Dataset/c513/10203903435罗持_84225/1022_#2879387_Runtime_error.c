#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
	char name[200];
	char zhu[200];
}a[1000010];
int mycmp(const void* xx,const void* yy)
{
	struct node x = *((struct node*)xx);
	struct node y = *((struct node*)yy);
	if(strcmp(x.zhu,y.zhu)==0) return strcmp(y.name,x.name);
	return strcmp(x.zhu,y.zhu);
}
int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		char s[300];
		scanf("%s",s);
		int idx = 0;
		for(int j=0;j<strlen(s);j++)
		{
			if(s[j]=='@')
			{
				idx = j;
				break;
			}
		}
		strncpy(a[i].name,s,idx);
		strcpy(a[i].zhu,s+idx+1);
	}
	qsort(a+1,n,sizeof(a[0]),mycmp);
	for(int i=1;i<=n;i++)
		printf("%s@%s\n",a[i].name,a[i].zhu);
	return 0;
}