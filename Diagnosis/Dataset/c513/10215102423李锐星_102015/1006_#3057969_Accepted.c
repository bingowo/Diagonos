#include <stdio.h>
#include <string.h>

void solve()
{
	char s[1001];
	scanf("%s",s);
	int len=strlen(s);
	int i;
	long long weight=1;
	long long res=0;
	for (i=len-1;i>-1;i--){
		if(s[i]=='-') res-=weight;
		else if(s[i]=='0');
		else res+=weight;
		weight*=3;
	}
	printf("%lld\n",res);
	
}

int main()
{
	int T;
	scanf("%d",&T);
	for (int i=0;i<T;i++){
		printf("case #%d:\n",i);
		solve();
	}
	return 0;
}