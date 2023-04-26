#include<stdio.h>
int GCD(int a,int b){return a%b?GCD(b,a%b):b;}
int int2tern(const void* a,int mole,int deno)
{
	if(deno==1)
	{
		int* tern=(int*)a;
		int i=0;
		for(i;mole;i++)
		{
			tern[i]=mole%3;
			mole/=3;
		}
		int length=i;
		for(int j=--i,k=0;k<=j;k++,j--)
		{
			int temp=tern[k];
			tern[k]=tern[j];
			tern[j]=temp;
		}
		return length;
	}
	else if(mole<deno)
	{
		int* tern=(int*)a;
		int i;
		for(i=0;;i++)
		{
			deno/=3;
			if(mole%deno==0)
			{
				tern[i]=mole%deno;
				break;
			}
			else if(mole>2*deno)
			{
				tern[i]=2;
				mole-=deno*2;
			}
			else if(mole>deno)
			{
				tern[i]=1;
				mole-=deno;
			}
			else tern[i]=0;
		}
	}
	else
	{
		int n=mole/deno;
		mole%=deno;
		int* tern=(int*)a;
		int i=0;
		for(i;n;i++)
		{
			tern[i]=mole%3;
			mole/=3;
		}
		for(int j=--i,k=0;k<=j;k++,j--)
		{
			int temp=tern[k];
			tern[k]=tern[j];
			tern[j]=temp;
		}
		i++;
		for(i;;i++)
		{
			deno/=3;
			if(mole%deno==0)
			{
				tern[i]=mole%deno;
				break;
			}
			else if(mole>2*deno)
			{
				tern[i]=2;
				mole-=deno*2;
			}
			else if(mole>deno)
			{
				tern[i]=1;
				mole-=deno*1;
			}
			else tern[i]=0;
		}
		return i;
	}
}
int add(const void* a,int length)
{
	int* tern=(int*)a;
	int i;
	for(i=length-1;i>=0;i--)tern[i+1]=tern[i];
	tern[0]=0;
	int carry=0;
	for(i=length;i>=1;i--)
	{
		tern[i]+=1;
		tern[i]+=carry;
		if(tern[i]>=3)
		{
			carry=1;
			tern[i]%=3;
		}
		else carry=0;
	}
	tern[0]=carry;
	if(tern[0]==0)
	{
		for(i=0;i<length;i++)tern[i]=tern[i+1];
		tern[length]=0;
		return 0;
	}
	return 1;
}
int main()
{
	int mole,deno;
	scanf("%d%d",&mole,&deno);
	int div=GCD(mole,deno);
	mole/=div;
	deno/=div;
	int tern[300],length,state;
	for(int i=0;i<300;i++)tern[i]=0;
	length=int2tern(tern,mole,deno);
	state=add(tern,length);
	if(state==1)
	{
		for(int i=length;i>=1;i--)
		{
			tern[i]-=1;
			if(tern[i]==-1)tern[i]=2;
		}
	}
	else
	{
		for(int i=length-1;i>=0;i--)
		{
			tern[i]-=1;
			if(tern[i]==-1)tern[i]=2;
		}
	}
	int i,j;
	for(i=0;i<300;i++)if(tern[i])break;
	for(j=300;j>=0;j--)if(tern[j])break;
	for(i;i<=j;i++)printf("%d",tern[i]);
	return 0;
}
	