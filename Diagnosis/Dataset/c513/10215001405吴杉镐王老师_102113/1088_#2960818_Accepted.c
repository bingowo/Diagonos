#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n,m,T;
long long C[45][45];
int main()
{
    for(int i=1;i<=40;i++)
        C[i][i]=C[i][0]=1;
    for(int i=1;i<=40;i++)
        for(int j=i+1;j<=40;j++)
            C[j][i]=C[j-1][i-1]+C[j-1][i]; //按照列来构造！
    scanf("%d",&T);
    for(int c=0;c<T;c++)
    {
        scanf("%d%d",&n,&m);
        printf("case #%d:\n%lld\n",c,C[n][m]); //刚刚好！
    }
    return 0;
}
//杨辉三角 OMG！
//记住构造方式！（这个比较特别）
