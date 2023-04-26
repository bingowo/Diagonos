#include<stdio.h>
//读到一个比第一个大的就放在前面，反之后面 
int main()
{
	char c,s[1001];int cnt=1,i; 
	s[0]=getchar();s[0]=s[0]>=97?s[0]-32:s[0];
	while((c=getchar())!=EOF)
	{
		c=c>=97?c-32:c;
		if(s[0]>c){s[cnt++]=c;}//for(i=0;i<cnt;i++)printf("%c",s[i]); printf("\n");}
		else
		{
			for(i=cnt;i>0;i--)s[i]=s[i-1];
			s[0]=c;
			cnt++;
			//for(i=0;i<cnt;i++)printf("%c",s[i]);
			//printf("\n");
		}
	}
	s[cnt]=0;printf("%s",s);
	return 0;
}