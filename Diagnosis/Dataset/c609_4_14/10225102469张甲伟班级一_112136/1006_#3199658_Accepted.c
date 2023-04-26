#include <stdio.h>
int T,a[1000],R;
long long ans;
int main()
{
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		char s[100];
		scanf("%s",s);
		for(int j=0;j<128;j++)
			a[j]=-1;
		R=0;
		char *p=s;
		a[*p]=1;
		while(*++p)
		{
			if(a[*p]==-1)
			{
				a[*p]=R;
				R=R?R+1:2;
			}
		}
		if(R<2)
			R=2;
		ans=0;
		p=s;
		while(*p)
		{
			ans=ans*R+a[*p++];
		}
		printf("case #%d:\n",i);
		printf("%lld\n",ans);
	}
	return 0;
}