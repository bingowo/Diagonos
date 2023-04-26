#include<stdio.h>
#include<stdlib.h>
#include<string.h>
float fq[200];
int cmp(const void*a,const void*b)
{
	char c=*(char*)a;
	char d=*(char*)b;
	char c1=c,c2=d;
	if(c>90)//小写转大写 
	{
		c1=c1-32;
	}
	if(d>90)
	{
		c2=c2-32;
	}
	if(fq[c1]!=fq[c2])
	{
		if(fq[c1]>fq[c2])
		{
			return -1;
		}
		else return 1;
	}
	else{
		return d-c;
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		int j=0;
		for(j=65;j<=90;j++)
		{
			scanf("%f",&fq[j]);
		}
		char s[101]={0};
		scanf("%s",s);
		qsort(s,strlen(s),sizeof(s[0]),cmp);
		printf("case #%d:\n",i);
		printf("%s\n",s);
	//	printf("%f %f\n",fq['a'-32],fq['o'-32]);
	}
}