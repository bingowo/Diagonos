#include <stdio.h>
#include <string.h>


int main()
{
	int t,m;
	scanf("%d",&t);
	for(m=0;m<t;m++)
	{
		int str_len,line_len,i,p;
		char s[2001];
		scanf("%d",&line_len);
		int cc;
		while((cc=getchar())!='\n'&&cc!=EOF);
		gets(s);
		
		str_len=strlen(s);
		int words_len,words_count,space,j;
		for(i=0;s[i]==' ';i++);
		printf("case #%d:\n",m);
		while(i<str_len)
		{
			int start=i;
			words_len=0;words_count=0;
			for(;words_len+words_count<=line_len&&i<str_len;)
			{
				int l;
				for(l=0,p=i;s[p]!=' '&&p<str_len;p++,l++);
				
				if(words_len+words_count+l<=line_len)
				{
					words_len+=l;
					words_count++;
					for(i=p;s[i]==' ';i++);
				}
				else break;
				
			}
			//printf("hhh");
			space=line_len-words_len;
			j=start;
			words_count--;
			while(j<i)
			{
				while(s[j]!=' '&&j<str_len) putchar(s[j++]);
				while(s[j]==' '&&j<str_len) j++;
				if(i==str_len&&words_count) putchar(' ');
				else{
					for(p=0;words_count&&p<space/words_count;p++) putchar(' ');
					space-=p;
				}
				words_count--;
				
			}
			//printf("hhh\n");
			printf("\n");
	
		}
	
	}
	return 0;
 } 