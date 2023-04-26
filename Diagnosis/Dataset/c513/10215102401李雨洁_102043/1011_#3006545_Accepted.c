#include <stdio.h>
#include <string.h>

int main()
{
	getchar();
	getchar();
	char s[100];
    int a[1111],b[100];
	long long ans1=0,ans2=0,p1=-1,p2=1,now1=1,now2=0;
	for(int i = 1; i < 1111; i++) a[i]=0;
	gets(s);
	for(int i = 0; i < strlen(s); i++)
	{
		if(s[i] >= '0' && s[i] <= '9') b[i] = s[i]-'0';
		if(s[i] >= 'A' && s[i] <= 'Z') b[i] = s[i]-'A'+10;
		for(int j = 4 * i + 3; j >= 4 * i; j--)
		{
			a[j] = b[i] % 2;
			b[i] /= 2;
		}
	}
	for(int i = 4 * (int)strlen(s) - 1; i >= 0; i--)
	{
		if(a[i] & 1)
		{
			ans1 += now1;
			ans2 += now2;
		}
		long long temp1 = now1 * p1 - now2 * p2;
		long long temp2 = now1 * p2 + now2 * p1;
		now1 = temp1;
		now2 = temp2;
	}
	if(ans1 != 0)
	{
		if(ans2 > 1) printf("%lld+%lldi\n",ans1,ans2);
		if(ans2 == 1) printf("%lld+i\n",ans1);
		if(ans2 == 0) printf("%lld\n",ans1);
		if(ans2 == -1) printf("%lld-i\n",ans1);
		if(ans2 < -1) printf("%lld%lldi\n",ans1,ans2);
	}
	if(ans1 == 0)
	{
		if(ans2 > 1 || ans2 < -1) printf("%lldi\n",ans2);
		if(ans2 == 1) printf("i\n");
		if(ans2 == 0) printf("0\n");
		if(ans2 == -1) printf("-i\n");
	}
	return 0;
}


