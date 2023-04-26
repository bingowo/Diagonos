#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int maxlen=0;
int start=0;
int alpha[10000];
char s[1000005];
int main()
{
	scanf("%s",s);
	for(int i=0;i<128;i++)
		alpha[i]=-1;
	int tap=0;
	for(int i=0;s[i];i++)
	{
		char c=s[i];
		if(alpha[c]>=tap)
		{
			tap=alpha[c]+1;
			alpha[c]=i;
		}
		else
		{
			alpha[c]=i;
			if(maxlen<i-tap+1)
			{
				start=tap;
				maxlen=i-tap+1;
			}
		}
	}
	for(int i=start;i<=maxlen;i++)
		printf("%c",s[i]);
	return 0;
}