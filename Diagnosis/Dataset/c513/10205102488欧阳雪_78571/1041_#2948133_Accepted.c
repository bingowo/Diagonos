#include<stdio.h>
#include<string.h>
int main()
{
	char s[100]={0};
	scanf("%s",s);
	int cnt=1;
	int i=1;
	while(s[i])
	{
		int t=1;
		int temp=i;
		while(s[temp]!=s[temp-1]&&s[temp])
		{
			t++;
			temp++;
		}
		if(cnt<t)
		{
			cnt=t;
		 }
		i++; 
	}
	printf("%d",cnt);
 } 