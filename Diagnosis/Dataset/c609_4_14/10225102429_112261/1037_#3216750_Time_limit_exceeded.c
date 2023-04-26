#include <stdio.h>
#include <string.h>
int a[128];
#define Maxlen 1000000
char s[Maxlen];
int main()
{
	scanf("%s",s);
	memset(a,0,sizeof(a));
	int begin = 0,end = 0,rb = 0,re = 0;
	for(; re<strlen(s); re++)
	{
		if(!a[s[re]])
		{
			a[s[re]] = 1;
		}
		else
		{
//			rb = beg
			while(s[rb]!=s[re])
			{
				a[s[rb]] = 0;
				rb++;
			}
			rb++;
//			re = end+1;
//			printf("%d\n",rb);
		}
		if(end-begin<re-rb)
		{
			end = re; begin = rb;
		}
	}
	for(int i = begin; i<=end; i++)
	{
		printf("%c",s[i]);
	}
//	printf("\n");
//	printf("begin = %d end = %d rb = %d re = %d",begin,end,rb,re);
	return 0;
}