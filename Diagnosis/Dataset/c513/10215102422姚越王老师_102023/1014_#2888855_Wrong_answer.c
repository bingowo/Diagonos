#include<stdio.h>
void int2tern(int* tern,int in,int a,int b)
{
	int i=0,length=0;
	if(in)
	{
		for(i;;i++)
		{
			tern[i]=in%3;
			in/=3;
			if(in==0)break;
		}
		length=i+1;
		for(int j=0;j<i;j++,i--)
		{
			int tmp=tern[j];
			tern[j]=tern[i];
			tern[i]=tmp;
		}}
	else {}
	if(a==0)return;
	for(i=length;;i++)
	{
		b/=3;
		if(b==1)
		{
			tern[i]=a;
			break;
		}
		else if(a<b)tern[i]=0;
		else if(a==b)
		{
			tern[i]=1;
			break;
		}
		else if(a<2*b)
		{
			tern[i]=1;
			a-=b;
		}
		else if(a==2*b)
		{
			tern[i]=2;
			break;
		}
		else 
		{
			tern[i]=2;
			a-=2*b;
		}
	}
}
int main()
{
	int in,a,b;
	scanf("%d%d",&a,&b);
	in=a/b;a%=b;
	int tern[10]={0};
	int2tern(tern,in,a,b);
	int i,j;
	for(i=0;i<10;i++)if(tern[i])break;
	for(j=9;j>=0;j--)if(tern[j])break;
	for(i;i<=j;i++)printf("%d",tern[i]);
	return 0;
}
	