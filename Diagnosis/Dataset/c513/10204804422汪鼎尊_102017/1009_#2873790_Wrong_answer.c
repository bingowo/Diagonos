#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
	int result,len;
	int i,t;
	char c;
	
	int ca,cases;
	scanf("%d",&cases);getchar();
	for(ca=0;ca<cases;ca++)
	{
		result=0;len=0;
		while(1)
		{
			c=getchar();
			if(c=='\n'||c=='\0')break;
			for(i=0;i<32;i++)if((c>>i)&1)result++;
			len+=8;
		}
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