#include <stdio.h>
#include <string.h>

int main()
{
	char s[105]={0},ans[200]={0};
	int cnt=0;
	scanf("%s",s);
	int len = strlen(s),i=1;
	
	while(i<len)
	{
		ans[cnt++]=s[i-1];
		if(s[i-1]<s[i])
			ans[cnt++]=s[i-1],i++;
		else if(s[i-1] == s[i])
		{
			int a = i;
			while(s[a-1]==s[a] && a<=len)
				a++;
			if(s[a-1]>s[a])
			{
				while(i<a)
					ans[cnt++]=s[i++];
				i++;
			}else if(s[a-1]<s[a])
			{
				ans[cnt++]=s[i-1];
				while(i<a)
					ans[cnt++]=s[i],ans[cnt++]=s[i++];
				i++;
			}
		}
		else i++;
	}
	ans[cnt++]=s[len-1],ans[cnt++]='\0';
	printf("%s\n",ans);
	return 0;
}