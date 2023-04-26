#include<stdio.h>
#include<string.h>
int main()
{
	int t;
	scanf("%d",&t);
	int k;
	for(k=0;k<t;k++)
	{
		char oct[51],dec[149];
		scanf("%s",oct);
		int len=strlen(oct);  //八进制小数总长度
		int i; 
		double div=0;  //被除数，加上上一位再除以8
		for(i=len-1;i>1;i--)
		{
			//printf("%d\n",oct[i]-'0');
			div+=(double)(oct[i]-'0');
			//printf("+div%lf\n",div);
			div/=8.0;
		}
		printf("case #%d:\n",k);
		printf("%lf\n",div);
	}
} 