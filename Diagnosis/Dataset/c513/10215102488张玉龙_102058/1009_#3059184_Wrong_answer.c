#include<stdio.h>
#include<string.h>
int main()
{
	int t;
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		char c[121]="";
		gets(c);
		int len1=strlen(c),len2=0,time=0;
		for(int i=0;i<len1;i++)
		{
			int a=c[i];
			int num[300]={0};
			int j=0;
			do
			{
				num[j]=a%2;
				a=a/2;
				if(num[j]==1)
				{
					time++;
				}
				j++;
			}
			while(a>0);
			len2+=8;	
		}
		int tmp,a1=len2,a2=time;
		while(tmp=a1%a2)
		{
			a1=a2;
			a2=tmp;
		}
		printf("%d/%d",time/a2,len2/a2); 
	}
	return 0;
}