#include<stdio.h>
#include<ctype.h>
#include<string.h>
long long mulreal(long long qr,long long qi)
{
	return -qr-qi;
}
long long mulimag(long long qr,long long qi)
{
	return qr-qi;
}
int main()
{
	char s[1005];scanf("%s",s);
	int length=(strlen(s)-2)*4;
	int bina[length];
	for(int i=0;i<length;i++)bina[i]=0;
	for(int i=2;s[i];i++)
	{
		int d=(i-2)*4+3;
		if(isdigit(s[i]))
		{
			int n=s[i]-48;
			while(n)
			{
				bina[d--]=n%2;
				n/=2;
			}
		}
		else
		{
			int n=s[i]-55;
			while(n)
			{
				bina[d--]=n%2;
				n/=2;
			}
		}
	}
	long long int qr=1,qi=0,a,b;
	int cnt=0;
	while(!bina[cnt++]);
	for(cnt;cnt<length;cnt++)
	{
		a=mulreal(qr,qi);
		b=mulimag(qr,qi);
		a+=bina[cnt];
		qr=a;qi=b;
	}
	printf("%lld-%lldi",qr,qi);
	return 0;
}