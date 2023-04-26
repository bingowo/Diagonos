#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct data
{
	char s[];
	int a;
	int b;
	int l;
};
int cmp(const void *pa,const void *pb)
{
	struct data a,b;
	a=*((struct data *)pa);
	b=*((struct data *)pb);
	if(a.a!=b.a)
	{
		return b.a-a.a;
	}
	else
	{
		return a.b-b.b;
	}
}
int main()
{
	int number;
	scanf("%d",&number);
	for(int i=0;i<number;i++)
	{
		int n;
		scanf("%d",&n);
		struct data p[n];
		for(int j=0;j<n;j++)
		{
			scanf("%s",&p[j].s);
			p[j].l=strlen(p[j].s);
			int t=1;
			int u=0;
			for(int k=1;k<p[j].l;k++)
			{
				for(int q=0;q<k;q++)
				{
					if(p[j].s[q]==p[j].s[k])
					{
						continue;
					}
					else
					{
						if(p[j].s[k]>p[j].s[q])
						{
							u++;
						}
						t++;
					}
					
				}
			}
			p[j].a=t;
			p[j].b=u;
		}
		qsort(p,n,sizeof(p[0]),cmp);
		printf("case #%d:\n",i);
		for(int m=0;m<n;m++)
		{
			for(int g=0;g<p[m].l-1;g++)
			{
				printf("%d",p[m].a);
			}
			printf("%c\n",p[m].s[p[m].l-1]);
		}
	}
	return 0;
}