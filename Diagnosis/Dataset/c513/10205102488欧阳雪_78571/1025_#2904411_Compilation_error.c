#include<stdio.h>
#include<stdlib.h>
#incldue<string.h>
struct string{
	char s[100];
	int count;
};
int cmp(const void*a.const void*b)
{
	struct string sa=*(struct string*)a;
	struct string sb=*(struct string*)b;
	if(sa.count !=sb.count ){
		return(sb.count -sa.count );
	}
	return(sa.s -sb.s );
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		struct string st[100];
		int n;
		scanf("%d",&n);
		char c;
		for(int j=0;j<n;j++)
		{
			int a[1000]={0};
			int t=0;
			while((c=getchar())!='\n')
			{
				a[c]++;
				st[j].s[t++]=c;
			}
			st[j].s [t]=0;
			for(int k=0;k<1000;k++)//找不同字符个数 
			{
				if(a[k]>0)
				{
					st[j].count ++;
				}
			}
		}
		qsort(st,n,sizeof(st[0]),cmp);
		printf("case #%d:\n",i);
		for(int k=0;k<n;k++)
		{
			printf("%s\n",st[k].s );
		}
	}
}