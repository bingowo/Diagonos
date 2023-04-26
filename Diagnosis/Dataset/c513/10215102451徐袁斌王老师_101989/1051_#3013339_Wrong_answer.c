#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int t,a[808];
    char s[101],ans[200];
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
		scanf("%s",s);
		int k=0,m=0;
		for(int j=0;j<200;j++) ans[j]=0;
		for(int j=0;s[j]!='\0';j++)
		{
			char b=s[j];
			for(int o=0;o<8;o++)
			{
				a[k+7-o]=b%2;
				b=b>>1;
			}
			k=k+8;
		}
		k--;
		while((k+1)%6!=0){a[k]=0;k++;}
		a[k]=0;
		for(int o=0;o<k;)
		{
			char n=0;
			for(int p=0;p<6;p++)
			{
				n=n*2+a[o];o++;
			}
			if(n<=25) ans[m]=n+'A';
			else if(n<=51) ans[m]=n+'a'-26;
			else if(n<=61) ans[m]=n+'0'-52;
			else if(n==62) ans[m]='+';
			else if(n==63) ans[m]='/';
			m++;
		}
		while(m%4!=0){ans[m]='=';m++;}
		ans[m]='\0';
		printf("case #%d:\n%s\n",i,ans);
		
		
	}
}

