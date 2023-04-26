#include<stdio.h>
#include<stdlib.h>
int cmp(const void *pa,const void *pb)
{
	int a,b;
	a=*((int *)pa);
	b=*((int *)pb);
	return a-b;
}
int zhishu(int n)
{
    int t=1;
    for(int i=0;i<n;i++)
    {
        t=t*2;
    }
    return t;
}
int min(int a[8])
{
	int result[8];
	for(int i=0;i<8;i++)
	{
		result[i]=0;
	}
	for(int i=0;i<8;i++)
	{
		int t=a[0];
		for(int j=0;j<7;j++)
		{
			a[j]=a[j+1];
		}
		a[7]=t;;
		for(int j=7;j>=0;j--)
		{
			result[i]=result[i]+a[j]*zhishu(7-j);
		}
	}
	qsort(result,8,sizeof(int),cmp);
	return result[0];
}
int main()
{
    int n,m;
    scanf("%d%d",&m,&n);
    int a[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=1;i<n-1;i++)
    {
        for(int j=1;j<m-1;j++)
        {
            int b[8];
    		b[0]=a[i-1][j-1]>=a[i][j]?1:0;
    		b[1]=a[i-1][j]>=a[i][j]?1:0;
    		b[2]=a[i-1][j+1]>=a[i][j]?1:0;
    		b[3]=a[i][j+1]>=a[i][j]?1:0;
    		b[4]=a[i+1][j+1]>=a[i][j]?1:0;
    		b[5]=a[i+1][j]>=a[i][j]?1:0;
    		b[6]=a[i+1][j-1]>=a[i][j]?1:0;
    		b[7]=a[i][j-1]>=a[i][j]?1:0;
    		printf("%d ",min(b));
        }
        printf("\n");
    }
    return 0;
}