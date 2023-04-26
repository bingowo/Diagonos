#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int n;
char s[1005];
int l,cnt,pos;
int flag=1,num[100],ans[1005];
int main()
{
	scanf("%s",s);
	if(s[0]=='-')
		flag=-1;
	l=strlen(s);
	for(int i=l-1;i>=0;i--)
	{
		if(s[i]=='-')
			break;
		num[++cnt]=s[i]-'0';	
	}
	while(cnt)
	{
		if(num[1]%2==1)
		{
			if(flag==-1)
				num[1]++;
			else num[1]--;
			ans[++pos]=1;
		}
		else
			ans[++pos]=0;
		for(int i=cnt;i>0;i--)
		{
			num[i-1]+=10*(num[i]%2);//借位 
			num[i]/=2;
		}
		while(cnt>0&&num[cnt]==0)
			cnt--;
		flag*=-1;
	}
	for(int i=pos;i>0;i--)
		printf("%d",ans[i]);
	return 0;
 } 