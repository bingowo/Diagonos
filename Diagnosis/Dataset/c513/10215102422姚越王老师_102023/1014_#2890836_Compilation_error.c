#include<stdio.h>
int int2tern(int* tern,int in)
{
	int i=0;
	for(i;;i++)
	{
		tern[i]=in%3;
		in/=3;
		if(in==0)break;
	}
	for(int k=0;k<i;k++,i--)
	{
		int tmp=tern[k];
		tern[k]=tern[i];
		tern[i]=tmp;
	}
}
int point2tern(int* tern,int a,int b)
{
	if(a==0)return 0;
	int j=0;
	for(j;;j++)
	{
		b/=3;
		if(a%b==0)
		{
			tern[j]=a/b;
			break;
		}
		else
		{
			tern[j]=a/b;
			a%=b;
		}
	}
	int po_length=j+1;
	return po_length;
}
void add(int* tern,int length)
{
	int carry=0,i;
	for(i=length;i>=1;i--)
	{
		tern[i]+=1;
		tern[i]+=carry;
		if(tern[i]>=3)
		{
			tern[i]%=3;
			carry=1;
		}
		else carry=0;
	}
	tern[i]=carry;
	//printf("addresult:\n");
	//for(i=0;i<=length;i++)printf("%d",tern[i]);
	//printf("\n");
}
void sub(int* tern,int length)
{
	for(int i=length;i>=1;i--)
	{
		tern[i]-=1;
		if(tern[i]==-1)tern[i]=2;
	}
	//printf("subresult:\n");
	//for(int i=0;i<=length;i++)printf("%d",tern[i]);
	//printf("\n");
}
int main()
{
	int in,a,b;
	scanf("%d%d",&a,&b);
	in=a/b;a%=b;
	//printf("in=%d,a=%d,b=%d\n",in,a,b);
	int tern_int[10]={0},tern_point[10]={0};
	int2tern(tern_int,in);
	//printf("int2tern:\n");
	//for(int i=0;i<10;i++)printf("%d",tern_int[i]);
	//printf("\n");
	point2tern(tern_point,a,b);
	//printf("point2tern:\n");
	//for(int i=0;i<10;i++)printf("%d",tern_point[i]);
	//printf("\n");
	int l,j,length_int,length_point;
	for(l=9;l>=0;l--)
		if(tern_int[l])break;
	for(j=9;j>=0;j--)
		if(tern_point[j])break;
	length_int=l+1;length_point=j+1;
	//printf("leng_int=%d,length_point=%d\n",length_int,length_point);
	if(length_point==0)
	{
		int total[length_int+1]={0};
		for(int k=1;k<length_int+1;k++)total[k]=tern_int[k-1];
		add(total,length_int);
		sub(total,length_int);
		if(!total[0])for(int i=1;i<=length_int;i++)printf("%d",total[i]);
		else for(int i=0;i<=length_int;i++)printf("%d",total[i]);
		return 0;
	}
	else
	{
		int total[length_int+1+length_point]={0};
		for(int k=1;k<length_int+1;k++)total[k]=tern_int[k-1];
		for(int k=length_int+1;k<length_int+1+length_point;k++)total[k]=tern_point[k-length_int-1];
		add(total,length_int+length_point);
		sub(total,length_int+length_point);
		if(!total[0])
		{
			for(int i=1;i<=length_int;i++)printf("%d",total[i]);
			printf(".");
			for(int i=length_int+1;i<length_int+1+length_point;i++)printf("%d",total[i]);
			return 0;
		}
		else 
		{
			for(int i=0;i<=length_int;i++)printf("%d",total[i]);
			printf(".");
			for(int i=length_int+1;i<length_int+1+length_point;i++)printf("%d",total[i]);
			return 0;
		}
		return 0;
	}
}