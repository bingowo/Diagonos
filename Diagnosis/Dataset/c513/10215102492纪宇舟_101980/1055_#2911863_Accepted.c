#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int tab[256];
int main()
{
	char s[1000001];
	scanf("%s",s);
	int n=strlen(s);
	memset(tab,-1,sizeof(tab));
	int last=0,ans=0,pos=0;
	for(int i=0;i<n;i++)
	{
		if(tab[s[i]]!=-1)
		{
			if(tab[s[i]]>=last)
			{
				if(i-last>ans)
				{
					ans=i-last;pos=last;
				}
				last=tab[s[i]]+1;
			}
		}
		tab[s[i]]=i;
	}
	if(n-last>ans)
	{
		ans=n-last;pos=last;
	}
	for(int i=pos;i<pos+ans;i++)printf("%c",s[i]);
	return 0;
}