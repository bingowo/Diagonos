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
		int num=len/4;
		for(i=0;i<len;i++) r[s[i]]++;
		printf("case #%d:\n",w);
		printf("%d %d %d %d\n",num-r['R'],num-r['B'],num-r['Y'],num-r['G']);
		
	}
	return 0;
}