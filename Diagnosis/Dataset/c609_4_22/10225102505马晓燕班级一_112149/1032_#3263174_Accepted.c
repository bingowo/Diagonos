#include<stdio.h>

int main()
{
	char s[51]={0};
	int maxlen=1,temp=1,i=0;
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
	if(maxlen < temp)
		maxlen = temp;
	printf("%d\n",maxlen);
	return 0;
}