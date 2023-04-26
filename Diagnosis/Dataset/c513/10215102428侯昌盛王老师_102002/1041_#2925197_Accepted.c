#include <stdio.h>
#include <string.h>
int main()
{
	char s[51];
	scanf("%s",s);
	int len=strlen(s),i=0,n=1,max=0;
	while(i<len-1 || (len==1&&i==0))
	{
		
		
		for(i;i<len-1;i++)
		{
			if(s[i]!=s[i+1]) n++;
			else break;
				
		}
		
		i+=1;
		if(n>max) max=n;
		n=1;
	}

	printf("%d\n",max);
	return 0;
}