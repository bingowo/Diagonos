#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MOD 210//能被2，3，5，7同时除的算作一种情况 ，所以考虑2*3*5*7=210；
#define MAX 1000000007
int subint(char*s,int st,int de)
{
	int sum=0;
	for(;st<=de;st++)
	{
		sum=sum*10+s[st]-'0';
		sum%=MOD;
	}
	return sum;
}
int main()
{    int k,T;
	for(k=0;k<T;k++)
	{   char s[102]={'\0'};
		scanf("%s",s);
		int f[100][MOD]={0};//f(i,k)表示到第i个数字，对210取模为k的情况数 
		int i,j,k,l=strlen(s); 
		for(i=0;i<l;i++)
		{ 
			f[i][subint(s,0,i)]+=1;//不加符号，有且只有一个解 
			f[i][subint(s,0,i)]%=MAX;
			for(j=0;j<i;j++)
			{
				int tmp=subint(s,j+1,i);
				for(k=0;k<MOD;k++)
				{
					f[i][(k+MOD+tmp)%MOD]+=f[j][k];
					f[i][(k+MOD+tmp)%MOD]%=MAX;
					f[i][(k+MOD-tmp)%MOD]+=f[j][k];
					f[i][(k+MOD-tmp)%MOD]%=MAX;
				}
			}
		}
		 int ans;
		 for(i=0;i<MOD;i++)
		 { if(!(i%2)||!(i%3)||!(i%5)||!(i%7))//对210取模后的数为2，3，5，7的倍数 
		   {
		 	ans+=f[l-1][i];
		 	ans%=MAX;
		    }
		 	
		  } 
		  printf("%d\n",ans);
	}
	return 0;
}