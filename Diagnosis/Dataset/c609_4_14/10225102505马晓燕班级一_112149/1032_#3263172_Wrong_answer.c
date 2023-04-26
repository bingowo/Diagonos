#include<stdio.h>

int main()
{
	char s[51]={0};
	int maxlen=0,temp=1,i=0;
	scanf("%s",s);
	while(s[i+1] != '\0')
	{
		if(s[i] != s[i+1])
		{
			temp++;
		}
		else
		{
			if(maxlen < temp)
				maxlen = temp;
			temp = 1;
		}
		i++;
	}
	printf("%d\n",maxlen+1);
	return 0;
}