#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>

int main()
{
	char s[60];
	scanf("%s",s);
	int cnt[50]={0};
	int j=0;
	int l=strlen(s);
	for(int i=0;i<l-1;i++)
	{
		if(s[i]!=s[i+1]) cnt[j]++;
		else j++; 
	}
	//for(int i=0;i<=j;i++) printf("%d\n",cnt[i]);
	int ans=0;
	for(int i=0;i<=j;i++) if(ans<cnt[i]) ans=cnt[i];
	printf("%d\n",ans+1);
	return 0;
}