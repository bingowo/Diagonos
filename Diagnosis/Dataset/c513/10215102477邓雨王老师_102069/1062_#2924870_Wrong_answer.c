#include<stdio.h>
#include<string.h>
int a[1001][501];
void fun()
{
    int i,j,k;
    memset(a,0,sizeof(a));
    a[1][0]=1;
    a[2][0]=2;
    a[3][0]=4;
    a[4][0]=8;
    for(i=5; i<=1000; i++)
    {
        k=0;
        for(j=0; j<=500; j++)
        {
            a[i][j]=a[i-1][j]+a[i-2][j]+a[i-3][j]+a[i-4][j]+k;
            k=a[i][j]/10;
            a[i][j]=a[i][j]%10;
        }
    }
}
int main()
{
    fun();//调用函数预处理
    int n,i,j;
    scanf("%d",&n);
    int temp=n;
    while(n--)
    {
        int b;
        scanf("%d",&b);
        for(i=500; i>=0; i--)
        {
            if(a[b][i]!=0)
                break;
        }
        printf("case #%d:\n",temp-n);
        for( j=i; j>=0; j--)
            printf("%d",a[b][j]);
        printf("\n");
    }
    return 0;
}