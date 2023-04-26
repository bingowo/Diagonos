#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int T,ans[1000000],t;
char n[1000000];
int in[1000000],tmp;
int A,B; 
char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main()
{
		scanf("%d%s%d",&A,n,&B);
		int i=0,j=0;
		for(i=0;n[i]!='\0';i++)
		{
			if(n[i]-'0'>=0&&n[i]-'9'<=0)
				in[j++]=(n[i]-'0');
			else
				in[j++]=10+(toupper(n[i])-'A');
		}
		tmp=0;
		for(int k=0;k<j;k++)
		{
			tmp=tmp*A+in[k];
		}
		j=0;
		if(tmp==0)
		{
			printf("0");
			return 0;
		}
		while(tmp)
		{
			t=tmp%B;
			tmp/=B;
			ans[j++]=t;
		}
		for(int k=j-1;k>=0;k--)
		{
			printf("%c",table[ans[k]]);
		}
	return 0;
 } 