#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,i=0;
    long long arr[300];
    int rslt[300][20];
    //使用二维数组来存放结果
    scanf("%d",&t);
    while(i<t)scanf("%lld",arr+(i++));
    for(i=0;i<t;i++)
    {
        long long n=*(arr+i);
        int j=0;
        do
        {
            rslt[i][j++]=(int)(n%2333);
            rslt[i][j]=-1;      //用以判断每行的结束位置
        }while(n/=2333);
    }
    for(i=0;i<t;i++)
    {
        int j=0;
        while(rslt[i][++j]>=0);
        while(j-->0){printf("%d ",*(*(rslt+i)+j));}
        //每行倒置输出
        printf("\n");
    }
    return 0;
}
