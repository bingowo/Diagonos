#include<stdio.h>
#include<string.h>
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		char s[61];
		scanf("%s",s);
		int a[128];
		for(int j=0;j<128;j++)
			a[j]=-1;
		int R=0;
		char *p=s;
		a[*p]=1;
		while(*++p)
			if(a[*p]==-1){
				a[*p]=R;
				R=R?R+1:2;
			}
		if(R<2)
			R=2;
		long long n=0;
		p=s;
		while(*p)
			n=n*R+a[*p++];
		printf("case #%d:\n%lld\n",i,n);
	}
	return 0;
 } 