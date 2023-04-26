#include <stdio.h>
#include <string.h>
int main()
{
	int t,w;
	scanf("%d",&t);
	for(w=0;w<t;w++)
	{
		char s[101];
		int r[100];
		scanf("%s",s);
		memset(r,0,sizeof(r));
		int len=strlen(s),i;
		for(i=0;i<len;i++)
		{
			if(s[i]=='!')
			{
				if(i+4<len) r[s[i+4]]++;
				else r[s[i-4]]++;
			}
			
		}
		printf("case #%d:\n",w);
		printf("%d %d %d %d\n",r['R'],r['B'],r['Y'],r['G']);
		
	}
	return 0;
}