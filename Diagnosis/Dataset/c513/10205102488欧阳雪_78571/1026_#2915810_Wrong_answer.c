#include<stdio.h>
#include<math.h>
int a[110000]={0};
int flg[110000]={0};
int k=0;//记录min1,min2的下标 
int find(int*a,int n)//找最小 
{
	int min=a[0];
	for(int i=1;i<n;i++)
	{
		if(min>a[i]&&flg[i]!=-1)
		{
			min=a[i];
			k=i;
		}
	}
	return min;
}
int main()
{
	int n,min=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int j=0;j<(n/2);j++)
	{
		int min1=find(a,n);
		//printf("min1:%d %d\n",k,min1);
		flg[k]=-1;
		int min2=find(a,n);
		//printf("min2:%d %d\n",k,min2);
		flg[k]=-1;//两个k不一样 
		min+=abs(min1-min2);
	}
	printf("%d",min);
}