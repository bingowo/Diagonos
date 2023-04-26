#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int cal(int a,int b)
{
	if(b==0)return a;
	return cal(b,a%b);
}
int main()
{
	int T;scanf("%d\n",&T);
	char chr[256];
	//char* chr=(char*)malloc(256*sizeof(char));
	//memset(chr,0,sizeof(chr));
	//gets(chr);
	while(T--)
	{
		//scanf("%s",chr);
		gets(chr);
		int n=strlen(chr);
		int tol=n*8,sum=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<8;j++)
			if(chr[i]&(1<<j))sum++;
		}
		int x=cal(sum,tol);
		sum/=x;tol/=x;
		printf("%d/%d\n",sum,tol);
	}
	return 0;
}
