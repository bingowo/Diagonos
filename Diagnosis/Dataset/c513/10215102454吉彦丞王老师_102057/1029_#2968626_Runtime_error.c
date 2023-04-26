#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct data
{
	char h;
	int x;
};
int cmp1(const void *pa,const void *pb)
{
	char a,b;
	a=*((char *)pa);
	b=*((char *)pb);
	return a-b;
}
int cmp2(const void *pa,const void *pb)
{
	struct data a,b;
	a=*((struct data *)pa);
	b=*((struct data *)pb);
	return a.x-b.x;
}
int main()
{
	int number;
	scanf("%d%c",&number);
	for(int i=0;i<number;i++)
	{
		char s[200];
		gets(s);
		int l=strlen(s);
		int n=0;
		for(int j=0;j<l;j++)
		{
			if(s[j]>='A'&&s[j]<='Z')
			{
				n++;
			}
		}
		char c[n];
		char d[l-n];
		int b[n];
		int a[l-n];
		int t=0;
		int q=0;
		for(int j=0;j<l;j++)
		{
			if(s[j]<='Z'&&s[j]>='A')
			{
				c[t]=s[j];
				b[t]=j;
				t++;
			}
			else
			{
				d[q]=s[j];
				a[q]=j;
				q++;
			}	
		}
		qsort(c,n,sizeof(char),cmp1);
		struct data p[l];
		for(int j=0;j<n;j++)
		{
			p[j].h=c[j];
			p[j].x=b[j];
		}
		for(int j=n;j<l;j++)
		{
			p[j].h=d[j-n];
			p[j].x=a[j-n];
		}
		qsort(p,l,sizeof(p[0]),cmp2);
		printf("case #%d:\n",i);
		for(int j=0;j<l;j++)
		{
			printf("%c",p[j].h);
		}
		printf("\n");
	}
	return 0;
}