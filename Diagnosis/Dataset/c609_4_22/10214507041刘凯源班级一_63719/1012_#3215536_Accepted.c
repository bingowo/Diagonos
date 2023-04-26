#include <stdio.h>
#include <string.h>
int T;
int main(void)
{
	scanf("%d",&T);
	for(int kase=0;kase<T;kase++)
	{
		int k = 0,tmp,j,i;
		char s[60] = {0};
		char res[160] = {0};
		scanf("%s",s);
		int len = strlen(s);
		for(int i=len-1;i>=2;i--)
		{
			int num = s[i]-'0';
			for(j=0;j<k||num!=0;j++)
			{
				if(j<k) tmp = 10*num+(res[j]-'0');
				else tmp = 10*num;
				res[j] = tmp/8+'0';
				num = tmp%8;
			}
			k = j;
		}
		printf("case #%d:\n",kase);
		printf("0.%s\n",res);
	}
	return 0;
}