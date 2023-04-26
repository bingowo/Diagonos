#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char s[300][500];

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
	for(int i=0;i<=t;i++)
	{
		char c=getchar();//'\n'
//		c=getchar();

		int pos=0,x=0,max=0,flag=0;
//		while(c!='!'&& c!='?'&& c!=','&& c!='.' && c!=' ')//存入第一个单词
//		{
//			s[pos][x++] = c;
//			c=getchar();
//		}
//		s[pos][x]='\0';
//		pos++,x=0;
		//c=getchar();
		while(c!='\n')
		{
			if((c =='!'|| c =='?'||c ==','|| c=='.'|| c==' ') && flag==0)
			{	c=getchar();
				continue;
			}
			while(c!='!' && c!='?' && c!=',' && c!='.' && c!=' ')
			{
				s[pos][x++] = c;
				flag=1;
				c=getchar();
			}
			s[pos][x]='\0';
			if(x > max)
				max = x;
			for(int j=0;j<pos;j++)
			{
				if(strcmp(s[j],s[pos]) == 0)
				{
					for(int i=0;i<x;i++)
						s[pos][i]=0;
					pos--;
					break;
				}
			}
			x=0,pos++,flag=0;
			//c=getchar();
		}
		pos--;
		qsort(s,pos+1,sizeof(char)*500,cmp);
		
		if(i)	printf("case #%d:\n",i-1);
		for(int i=0;i<=pos;i++)
		{
			if(i<pos)	printf("%s ",s[i]);
			else		printf("%s\n",s[pos]);
		}
		
	}
	return 0;
}