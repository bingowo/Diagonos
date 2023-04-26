#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct 
{
	int num[50];
	int sp;
}n;
int t1[25]=
{
	2,3,5,7,11,
	13,17,19,23,29,
	31,37,41,43,47,
	53,59,61,67,71,
	73,79,83,89,91
}; 
n t2[100];
void multi(n* list,n a,int r)
{
	if(r==0)
	{
		list->num[0]=0;
		list->sp=0;
		return ;
	}
	int i=0,p=0,carry=0;
	while(i<=a.sp)
	{
		int temp=a.num[i]*r+carry;
		carry=temp/10;
		list->num[p++]=temp%10;
		i++;
	}
	while(carry!=0)
	{
		list->num[p++]=carry%10;
		carry/=10;	
	}
	list->sp=p-1;
}
void add(int* ans,n* b,int* top)
{
	int carry=0,i=0;
	for(;i<=b->sp;i++)
	{
		int temp=ans[i]+b->num[i]+carry;
		carry=temp/10;
		ans[i]=temp%10;
	}
	while(carry!=0)
	{
		ans[i++]=carry%10;
		carry/=10;	
	}
	*top=i-1;
}
int main()
{96,88,82,78,72,70,66,60,58,52,46,42,40,36,30,28,22,18,16,12,10,6,4,2,1

	int ans[150],top=0;
	t2[2].num[0]=1;t2[2].sp=0;
	for(int i=1;i<25;i++)
	{
		multi(&t2[t1[i]],t2[t1[i-1]],t1[i-1]);
	}
	for(int i=0;i<150;i++)ans[i]=0;
	
	n b,bin;int i=0;
	do
	{
		scanf("%d",&b.num[i++]);
	}while(getchar()==',');
	b.sp=bin.sp=i-1;int p=i-1;
	for(i=0;i<=bin.sp;i++)
		bin.num[i]=b.num[p--];
	for(i=0;i<=bin.sp;i++)
	{
		multi(&b,t2[t1[i]],bin.num[i]);
		add(ans,&b,&top);
	}
	for(int index=top;index>=0;index--)
		printf("%d",ans[index]);
	return 0;
}