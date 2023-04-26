#include<stdio.h>
#include<string.h>
int main()
{
	char s[51];
	scanf("%s",s);
	int len=strlen(s),i,j,max=-1,l;
	for(i=0;i<len;i++)
	{
		if(s[i+1]!=s[i])
		{
			j=i;
			for(i;i<len-1;i++)
			{
				if(s[i+1]==s[i])break;
			}
			l=i-j+1;
			if(l>max)
			{
				max=l;
			}
			//printf("l=%d i=%d j=%d\n",l,i,j);
		}
	}
	printf("%d",max);
	return 0;
}