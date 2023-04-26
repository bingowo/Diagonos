#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
	char in[61],ch,out[61];
	int cases,c;
	long long int result;
	int len,i,j,now;
	scanf("%d",&cases);
	for(c=0;c<cases;c++)
	{
		result=0;now=1;
		scanf("%s",&in);
		len=strlen(in);
		for(i=0;i<len;i++)
		{
			if(in[i]==0)continue;
			ch=in[i];
			for(j=i;j<len;j++)if(in[j]==ch)
			{
				out[j]=now;
				in[j]=0;
			}
			if(now==1)now=0;
			else if(now==0)now=2;
			else now++;
		}
		for(i=0;i<len;i++)
		{
			result*=(now>=2?now:2);
			result+=out[i];
		}
		printf("case #%d:\n%lld",c,result);
		if(c!=cases-1)printf("\n");
	}
	return 0;
}