#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
char s1[105],s2[105];
int ans[10];
int main()
{
	while(scanf("%s %s",s1,s2)==2)
	{
		if(s1[0]=='I')
		{
			ans[s2[0]-'A']=0;
			int cnt=0;
			while(s2[cnt]!=',')
				cnt++;
//			printf("%c\n",s2[cnt]);
			cnt++;
			int num=0;
			while(s2[cnt]!='\0')
			{
				num=num*10+s2[cnt]-'0';
				cnt++;
			}
			ans[s2[0]-'A']=num;
		}
		else if(s1[0]=='M'&&s1[1]=='O')
			ans[s2[0]-'A']=ans[s2[3]-'A'];
		else if(s1[0]=='A')
			ans[s2[0]-'A']+=ans[s2[3]-'A'];
		else if(s1[0]=='S')
			ans[s2[0]-'A']-=ans[s2[3]-'A'];
		else if(s1[0]=='M'&&s1[1]=='U')
			ans[s2[0]-'A']*=ans[s2[3]-'A'];
		else if(s1[0]=='D')
			ans[s2[0]-'A']/=ans[s2[3]-'A'];
		else 
			printf("%d\n",ans[s2[0]-'A']);
//		printf("%d %d %d %d\n",ans[0],ans[1],ans[2],ans[3]);
	}
	return 0;
 }