#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
	char in[61],ch;
	int cases,c,value[128];
	long long int result;
	int len,i,j,now;
	scanf("%d",&cases);
	for(c=0;c<cases;c++)
	{
		result=0;now=1;memset(value,-1,128*sizeof(int));
		scanf("%s",&in);
		len=strlen(in);
		for(i=0;i<len;i++)if(value[in[i]]==-1)
		{
			value[in[i]]=now;
			if(now==1)now=0;
			else if(now==0)now=2;
			else now++;
		}
		for(i=0;i<len;i++)
		{
			result*=(now>=2?now:2);
			result+=value[in[i]];
		}
		printf("case #%d:\n%lld",c,result);
		if(c!=cases-1)printf("\n");
	}
	return 0;
}