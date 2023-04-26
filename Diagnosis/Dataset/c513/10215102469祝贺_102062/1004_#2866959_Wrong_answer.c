#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char table[17]={"0123456789abcdef"};
void pr(int num)
{
	int tag=0;
	for(int i=0;i<32;i+=4)
	{
		int index=0;
		for(int j=i;j<i+4;j++)
			index=index*2+((num>>(31-j))&1);
		printf("%c",table[index]);tag++;
		if(!(tag%2) && tag<8)
			printf(" ");
		if(tag==8)printf("\n");
	}
}

void fpr(double num)
{
		int tag=0;
		for(int i=0;i<64;i+=4)
		{
			int index=0;
			long long* p=(long long*)&num;
			for(int j=i;j<i+4;j++)
				index=index*2+(((*p)>>(63-j))&1);
			printf("%c",table[index]);tag++;
			if(!(tag%2) && tag<16)
				printf(" ");
			if(tag==16)
				printf("\n");
		}
}
int main()
{
	char c;
	while((c=getchar())!=EOF)
	{
		int num=0,sign=1,nag=1,flag;
		while(c!=' '&&c!='\n')
		{
			if(c=='-')
			{
				sign=-1;c=getchar();
			}
			else if(c=='+')
			{
				sign=1;c=getchar();
			}
			
			while(c>='0' && c<='9')
			{
				num=num*10+c-'0';
				c=getchar();
			}
			
			//printf("%d %c\n",num,c);
			if(c=='.')
			{
				c=getchar();
				while(c>='0' && c<='9')
				{
					num=num*10+c-'0';
					nag*=10;
					c=getchar();
				}
			}
		}
		if(c==' '||c=='\n')
			{
				if(nag==1)pr(sign*num);
				else fpr(sign*1.0*num/nag);
			}
	}
	return 0;
}

