#include<stdio.h>
#include<string.h>

char table[64]={0};
int main()
{
	int t;
	scanf("%d",&t);
	
	for(int i=0;i<62;i++)				//建立字母编码表
	{
		if(i<26)
			table[i] = 'A' + i;
		else if(i<52)
			table[i] = 'a' + i - 26;
		else 
			table[i] = '0' + i - 52;
	}
	table[62]='+',table[63]='/';

	for(int i=0;i<t;i++)
	{
		int bin[805]={0};
		int a=0,b=0,j,last;
		char str[105]={0},ans[200]={0};
		scanf("%s",str);
		int len = strlen(str);
		
		for(int i=0;i<len;i++)
		{
			unsigned x=128;
			for(j=0;j<8;j++)
			{
				if(str[i] & x)
					bin[b] = 1;
				x = x >> 1,b++;
			}
		}
		if(len%3)
		{
			if(len%3 == 1)
				last = b + 4;
			else
				last = b + 2;
		}else
			last = b;
		//转BASE64
		last = last / 6;
		b=0;
		for(a=0;a<last;a++)
		{
			int temp = 0;
			for(int i=0;i<6;i++,b++)
			{
				temp = temp*2 + bin[b];
			}
			ans[a] = table[temp];
		}
		if(last%4)
			for(int i=0;i<4-(last%4);i++,a++)
				ans[a]='=';
		
		ans[a]='\0';
		printf("case #%d:\n%s\n",i,ans);
	}
	return 0;
}