#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
char s[55];
int main()
{
	scanf("%s",s);
	int n=strlen(s);
	int ans=0,cnt=1;
	for(int i=1;i<n;i++)
	{
		if(s[i]!=s[i-1])cnt++;
		else cnt=1;
		if(cnt>ans)ans=cnt;
	}
	printf("%d",ans);
	return 0;
}