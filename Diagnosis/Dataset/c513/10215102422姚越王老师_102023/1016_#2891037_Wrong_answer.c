#include<stdio.h>
int yushu(int a,int b)
{
	if(a>0||a%b==0)return a%b;
	else
	{
		int c=a/b+1;
		return a-c*b;
	}
}
int shang(int a,int b)
{
	if(a>0||a%b==0)return a/b;
	else return a/b+1;
}
int main()
{
	int n,r;scanf("%d%d",&n,&r);
	int s[100];
	int i,length;
	for(i=0;;i++)
	{
		int tmp=yushu(n,r);
		s[i]=tmp;
		n=shang(n,r);
		printf("n=%d,tmp=%d\n",n,tmp);
		if(n==0)break;
	}
	length=i+1;
	printf("length=%d\n",length);
	int j;
	for(j=0,i;j<i;j++,i--)
	{
		int tmp=s[j];
		s[j]=s[i];
		s[i]=tmp;
	}
	for(i=0;i<length;i++)
	{
		if(s[i]<10)printf("%d",s[i]);
		else printf("%c",s[i]+55);
	}
	return 0;
}