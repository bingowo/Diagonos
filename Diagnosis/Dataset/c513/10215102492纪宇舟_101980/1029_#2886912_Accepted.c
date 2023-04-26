#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int cmp(const void* a,const void* b)
{
	char x=*(char*)a;char y=*(char*)b;
	if(x<y)return -1;
	return 1;
}
int main()
{
	int ct=0,T;scanf("%d\n",&T);
	char s[205],ans[205];int table[205];
	while(T--)
	{
		int n,cnt=0;
		gets(s);n=strlen(s);
		for(int i=0;i<n;i++)
		{
			if(s[i]>='A'&&s[i]<='Z')
			{
				table[i]=1;ans[++cnt]=s[i];
			}
			else table[i]=0;
		}
		qsort(ans+1,cnt,sizeof(char),cmp);
		cnt=0;printf("case #%d:\n",ct++);
		for(int i=0;i<n;i++)
		if(table[i])printf("%c",ans[++cnt]);
		else printf("%c",s[i]);
		printf("\n");
	}
	return 0;
} 