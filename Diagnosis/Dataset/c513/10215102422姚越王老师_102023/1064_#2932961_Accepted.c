#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
int main()
{
	int T,i,j,k,q;scanf("%d\n",&T);
	char s[110],tmp[110];
	for(i=0;i<T;i++)
	{
		double a[110];
		int cnt=0;//cnt用于计数a中的数字位置 
		gets(s);
		for(j=strlen(s)-1;j>=0;j--)
		{
			if(isdigit(s[j]))
			{
				for(k=j-1;k>=0;k--)if(s[k]==' ')break;
				int t=k;
				q=0;for(++k;k<=j;k++)tmp[q++]=s[k]; tmp[q]=0;
				a[cnt++]=atof(tmp);
				j=t;
			}
			else if(s[j]=='+')a[cnt-2]=a[cnt-1]+a[cnt-2],cnt--;
			else if(s[j]=='-')a[cnt-2]=a[cnt-1]-a[cnt-2],cnt--;
			else if(s[j]=='*')a[cnt-2]=a[cnt-1]*a[cnt-2],cnt--;
			else if(s[j]=='/')a[cnt-2]=a[cnt-1]/a[cnt-2],cnt--;
		}
		printf("case #%d:\n%.6f\n",i,a[0]);
	}
	return 0;
}