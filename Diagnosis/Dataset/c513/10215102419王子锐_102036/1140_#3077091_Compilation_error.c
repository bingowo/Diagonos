#include<stdio.h>
void intersection(int a[],int n,int b[],int m)//求数组a[]与数组b[]的交集 
{
	
	int c[200];//定义一个n+m长的数组用c[]来存储交集元素 
	int i=0,j;//循环控制变量 
	for(int k=0;k<m;k++)//进行筛选
	{
		int flag=0;
		for(j=0;j<n;j++)
		{
			if(b[k]==a[j]){flag=1;break;}
		}
		if(flag)c[i++]=b[k];
	}
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int cas = 0; cas < T; cas++)
    {
        int m,a[100];
        scanf("%d",&m);
        for (int i = 0; i < m; i++)
        {
            int mi;
            scanf("%d",&mi);
            mi=a[i];
        }

void display(int a[],int n)//输出数组元素
{
	
	printf("\n");
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}

