#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void intersection(int a[],int n,int b[],int m,int c[])
{
	
	int i=0;//循环控制变量 
	for(int k=1;k<m+1;k++)//进行筛选
	{
		int flag=0;
		for(int j=1;j<n+1;j++)
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
    int Set[100][100];
    for (int cas = 0; cas < T; cas++)
    {
        scanf("%d",&Set[cas][0]);
        for (int i = 0; i < Set[cas][0]; i++)
        {
            scanf("%d",&Set[cas][i+1]);
        }
        if(cas!=0)intersection(Set[cas],Set[cas][0],Set[cas-1],Set[cas-1][0],Set[T]);
    }
    qsort(Set[T],100,sizeof(Set[T][0]),strcmp);
	for(int t = 0; t < 100 ;t++)
		printf("%d ",Set[T][t]);
}

