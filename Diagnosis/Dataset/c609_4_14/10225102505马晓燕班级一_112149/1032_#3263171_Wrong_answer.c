#include<stdio.h>

int main()
{
	char c,a=getchar();
	int maxlen,temp=0;
	while(c=getchar(), c!='\n')
	{
		if(a != c)
		{
			temp++;
		}
		else
		{
			if(maxlen < temp)
				maxlen = temp;
			temp = 0;
		}
		a = c;
	}
	printf("%d\n",maxlen+1);
	return 0;
}