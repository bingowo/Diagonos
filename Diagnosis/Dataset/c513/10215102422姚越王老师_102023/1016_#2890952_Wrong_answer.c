#include<stdio.h>
void trans(char* s,int n,int r)
{
	int i;
	for(i=0;;i++)
	{
		int tmp=n%r;char c;
		if(tmp<10)c=tmp+48;
		else c=tmp+55;
		s[i]=c;
		n/=r;
		if(n==0)break;
	}
	s[++i]=0;i--;
	for(int j=0,i;j<i;j++,i--)
	{
		char tmp=s[j];
		s[j]=s[i];
		s[i]=tmp;
	}
}
int main()
{
	int n,r;scanf("%d%d",&n,&r);
	char s[1005];
	trans(s,n,r);
	printf("%s",s);
	return 0;
}