#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void*pa,const void *pb)
{
	int a,b;
	a=*((int *)pa);
	b=*((int *)pb);
	return b-a;
}
int leave(char s[])
{
	int l=strlen(s);
	int a[l];
	for(int i=0;i<l;i++)
	{
		a[i]=0;
	 } 
	for(int i=1;i<l;i++)
	{
		if(s[i-1]==s[i])
		{
			a[i-1]=1;
			a[i]=1;
		}
	}
	int t=0;
	for(int i=0;i<l;i++)
	{
		if(a[i]==1)
		{
			t++;
		}
	}
	char str[l];
	int n=0;
	for(int i=0;i<l;i++)
	{
		if(a[i]==0)
		{
			str[n]=s[i];
			n++;
		}
	}
	str[n]='\0';
	if(t==1)
	{
		return t;
	}
	else if(t==0)
	{
		return 0;
	}
	else
	{
		return t+leave(str);
	}
}
int main()
{
    int number;
    scanf("%d",&number);
    for(int i=0;i<number;i++)
    {
        char s[101];
        scanf("%s",&s);
        int l=strlen(s);
        int m[128];
        for(int j=0;j<128;j++)
        {
        	m[j]=-1;
		}
		int num=0;
		char c[3];
		for(int j=0;j<l;j++)
		{
			if(m[s[j]]<0)
			{
				m[s[j]]=1;
				c[num]=s[j];
				num++;
			}
		}
		int len=strlen(c);
		int a[len*(l+1)];
		char str[len*(l+1)][201];
		for(int j=0;j<len;j++)
		{
			for(int k=0;k<l+1;k++)
			{
				for(int q=0;q<k&&q<l;q++)
				{
					str[j*(l+1)+k][q]=s[q];
				}
				str[j*(l+1)+k][k]=c[j];
				for(int q=k+1;q<l+1;q++)
				{
					str[j*(l+1)+k][q]=s[q-1];
				}
				str[j*(l+1)+k][l+2]='\0';
				a[j*(l+1)+k]=leave(str[j*(l+1)+k]);	
			}
		}
		qsort(a,len*(l+1),sizeof(int),cmp);
		printf("case #%d:\n",i);
		printf("%d\n",a[0]);
    }
    return 0;
}