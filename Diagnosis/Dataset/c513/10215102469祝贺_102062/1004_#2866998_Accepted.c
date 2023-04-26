#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char table[17]={"0123456789abcdef"};
void pr(long long num)
{
	for(int i=3;i>=0;i--)
	{
		int index1=0,index2=0;
		for(int j=i*8,k=i*8+4;j<i*8+4;j++,k++)
		{
			index1=index1*2+((num>>(31-j))&1);
			index2=index2*2+((num>>(31-k))&1);
		}
		printf("%c%c ",table[index1],table[index2]);
	}
	printf("\n");
}

void fpr(double num)
{
		for(int i=7;i>=0;i--)
		{
			int index1=0,index2=0;
			long long* p=(long long*)&num;
			for(int j=i*8,k=i*8+4;j<i*8+4;j++,k++)
			{
				index1=index1*2+(((*p)>>(63-j))&1);
				index2=index2*2+(((*p)>>(63-k))&1);
			}
			printf("%c%c ",table[index1],table[index2]);
		}
		printf("\n");
}
int main()
{
	char c;
	while((c=getchar())!=EOF)
	{
		long long num=0,sign=1,nag=1,flag;
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

