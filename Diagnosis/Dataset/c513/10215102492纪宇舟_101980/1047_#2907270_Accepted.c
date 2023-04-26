#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<malloc.h>
int main()
{
	int cnt;
	char c,last;
	int ct=0,T;scanf("%d\n",&T);
	while(T--)
	{
		cnt=0;last=0;
		printf("case #%d:\n",ct++);
		while(c=getchar())
		{
			if(c!=last||cnt==255)
			{
				if(last!=0)printf("%d%c",cnt,last);
				if(c=='\n')break;
				cnt=1;last=c;
			}
			else cnt++;
		}
		printf("\n");
	}
	return 0;
}