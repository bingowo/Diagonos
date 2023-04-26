#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

char s[255][300];
int cmp (const void*a,const void *b)
{
	int x = strcmp((char*)a,(char*)b);
//	char *m =(char*)a, *n = (char*)b;
	return x;
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		char c=getchar();
		c=getchar();

		int pos=0,x=0,max=0,flag=1;
		while(isalpha(c))//存入第一个单词
		{
			s[pos][x++] = c;
			c=getchar();
		}
		pos++,x=0;
		
		while(c=getchar(),c!='\n')
		{
			if(!isalpha(c) && flag==0)
				continue;
			if(isalpha(c))
			{
				s[pos][x++] = c;
				flag=1;
			}
			else
			{
				s[pos][x]='\0';
				if(x > max)
					max = x;
				for(int j=0;j<pos;j++)
				{
					if(strcmp(s[j],s[pos]) == 0)
					{
						for(int i=0;i<=x;i++)
							s[pos][i]=0;
						pos--;
						break;
					}
				}
				x=0,pos++,flag=0;
			}
//			if(c == '\n')
//				break;
		}
		pos--;
		qsort(s,pos+1,sizeof(char)*300,cmp);
		
		printf("case #%d:\n",i);
		for(int i=0;i<pos;i++)
		{
			printf("%s ",s[i]);
		}
		printf("%s\n",s[pos]);
	}
	return 0;
}