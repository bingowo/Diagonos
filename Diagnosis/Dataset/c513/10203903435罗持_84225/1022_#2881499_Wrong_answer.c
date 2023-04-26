#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
	char *name;
	char *zhu;
}a[1000010];
int mycmp(const void* xx,const void* yy)
{
	struct node x = *((struct node*)xx);
	struct node y = *((struct node*)yy);
	if(strcmp(x.zhu,y.zhu)==0) return strcmp(y.name,x.name);
	return strcmp(x.zhu,y.zhu);
}
char s1[1000010],s2[1000010],s3[1000010];
int main(void)
{
	int n;
	scanf("%d",&n);
	getchar();
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s1);
		int len = strlen(s1);
		int idx = 0;
		for(int j=0;j<len;j++)
		{
			if(s1[j]=='@')
			{
				idx = j;
				break;
			}
		}
		strncpy(s2,s1,idx);
		strcpy(s3,s1+idx+1);
		int l2 = idx;
		int l3 = len-idx-1;
		a[i].name = (char*)malloc((l2+10)*sizeof(char));
		a[i].zhu = (char*)malloc((l3+10)*sizeof(char));
		strcpy(a[i].name,s2);
		strcpy(a[i].zhu,s3);
		printf("%s@%s\n",a[i].name,a[i].zhu);
	}
	qsort(a+1,n,sizeof(a[0]),mycmp);
	for(int i=1;i<=n;i++)
		printf("%s@%s\n",a[i].name,a[i].zhu);
	return 0;
}