#include <stdio.h>
#include <string.h>
#define MAXN 100
int add1(char *a,int k)
{
	int i=k;
	while(i>=0){
		a[i]+=1;
		if(a[i]<='9') return i;
		a[i]='0';
		i--;
	}
	return i;
}
int main()
{
	int t,e;
	scanf("%d",&t);
	for(e=0;e<t;e++)
	{
		char a[MAXN]={'0'};
		scanf("%s",a+1);
		int len=strlen(a);
		//printf("%s\n",a);
		//printf("%d\n",len);
		int i,j;
		i=add1(a,len-1);
		//printf("%d\n",i);
		for(i=1;i<len;i++)
		{
		
			if(a[i]==a[i-1]) break;
		}
		//printf("%d\n",i);
		if(i!=len){
			i=add1(a,i);
			while(i>0)
			{
				if(a[i]!=a[i-1]) break;
				i=add1(a,i);
			}
			for(j=i+1;j<len;j++)
				a[j]=(j-i+1)%2+'0';
		}
		printf("case #%d:\n",e);
		if(a[0]!='0') printf("%c",a[0]);
		printf("%s\n",a+1);
	}
}