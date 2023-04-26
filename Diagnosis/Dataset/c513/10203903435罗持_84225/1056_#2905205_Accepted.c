#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int n;
char dict[5000][20] = {0};
char s[6000] = {0};
int mycmp(const void *aa,const void *bb)
{ 
	char *a = (char*)aa;
	char *b = (char*)bb;
	if(strlen(a) >= strlen(b)) return -1;
	else return 1;
}
int main(void)
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%s",&dict[i]);
	scanf("%s",s);
	qsort(dict,n,sizeof(dict[0]),mycmp);
	int len = strlen(s);
	int pos = 0;
	while(pos < len)
	{
		int have = 0;
		for(int i=0;i<n;i++)
		{
			if(pos+strlen(dict[i])<=len)
			{
				int flag = 1;
				for(int j=0;j<strlen(dict[i]);j++)
				{
					if(dict[i][j]!=s[pos+j])
					{
						flag = 0;
						break;
					}
				}
				if(flag)
				{
					printf("%s ",dict[i]);
					pos += strlen(dict[i]);
					have = 1;
					break;
				}
			}
		}
		if(have==0)
		{
			printf("%c ",s[pos]);
			pos++;
		}
	}
	return 0;
}