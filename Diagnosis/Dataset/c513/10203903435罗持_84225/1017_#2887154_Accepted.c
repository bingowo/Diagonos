#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
long long table[26] = {0};
int main(void)
{
	char s[100];
	scanf("%s",s);
	table['I'-'A'] = 1LL;
	table['V'-'A'] = 5LL;
	table['X'-'A'] = 10LL;
	table['L'-'A'] = 50LL;
	table['C'-'A'] = 100LL;
	table['D'-'A'] = 500LL;
	table['M'-'A'] = 1000LL;
	long long res = 0,idx=0,weigh=1;
	long long num[100] = {0};
	int len = strlen(s);
	int pos = 0;
	while(pos<len)
	{
		if(isalpha(s[pos]))
		{
			num[idx] = table[s[pos]-'A']*weigh;
			idx++;
		}
		else if(s[pos]=='(') weigh*=1000;
		else if(s[pos]==')') weigh/=1000;
		pos++;
	}
	for(int i=0;i<idx;i++)
	{
		if(i!=idx-1 && num[i]<num[i+1]) res -= num[i];
		else res+=num[i];
	}
	printf("%lld",res);
	return 0;
} 