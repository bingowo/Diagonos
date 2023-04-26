#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[10000001];

int main()
{
	int maxlen=1;
	long long start=0;
	int alpha[128];
	for(int i=0;i<128;i++) alpha[i]=-1;
	int t=0;
	char c;
	long long i=0;
	while((c=getchar())!='\n')
	{
		s[i]=c;
		if(alpha[c]>=t)
		{
			t=alpha[c]+1;
			alpha[c]=i;
		}
		else {
			alpha[c]=i;
			if(maxlen<i-t+1)
			{
				start=t;
				maxlen=i-t+1;
			}
		}
		i++;
		//printf("t=%d\n",t);
		//printf("start=%d\n",start);
	}
	//printf("maxlen=%d\n",maxlen);
	for(int j=0;j<maxlen;j++)
		printf("%c",s[j+start]);
	return 0;
}