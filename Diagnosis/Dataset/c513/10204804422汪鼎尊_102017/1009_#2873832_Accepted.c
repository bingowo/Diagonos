#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
	int result,len;
	int i,t,j;
	char s[250];
	
	int ca,cases;
	scanf("%d",&cases);getchar();
	for(ca=0;ca<cases;ca++)
	{
		result=0;len=0;
		gets(s);
		len=strlen(s);
		for(i=0;i<len;i++)for(j=0;j<8;j++)if((s[i]>>j)&1)result++;
		len=len*8;
		
		
		for(i=2;i<50;)
		{
			if(result%i==0&&len%i==0)
			{
				result=result/i;
				len=len/i;
			}
			else i++;
		}
		printf("%d/%d",result,len);
		if(ca!=cases-1)putchar('\n');
	}
	return 0;
}