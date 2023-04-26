#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define N 100
typedef struct { int cnt,v[N]; } BIGINT ;
BIGINT int2BIG(int x)  //int 转换成BIGINT，储存在数组里
{
    BIGINT R= {0,{0}};
    do
    {
        R.v[R.cnt++]=x%10;
        x/=10;
    } while (x>0);
    return R;
}
BIGINT mul(BIGINT S, BIGINT T)     //两个大整数相乘的模板
{
    BIGINT R= {S.cnt+T.cnt,{0}};
    for (int i=0; i<T.cnt; i++)
    {
         int t,k,j;
        int carry=0;
        for (j=0; j<S.cnt; j++)
        {
            t=S.v[j]*T.v[i]+carry+R.v[i+j];//多位数相乘
            R.v[i+j]=t%10;//个位
            carry=t/10;//进位
        }
        k=i+j;//这次的总位数
        while (carry>0)//因为这时候循环次数是正好的，所以需要有这个代码
        {
            t=carry+R.v[k];
            R.v[k]=t%10;
            carry=t/10;
            k++;
        }
    }
    if (R.v[S.cnt+T.cnt-1]==0) R.cnt--; //最高位0不统计在一个大整数的位数中
    return R;
}




int main()
{
   int t;
   scanf("%d",&t);
   for(int i=0;i<t;i++)
   {
       int a,n;
       BIGINT R;
       scanf("%d %d",&a,&n);
       R=pow(int2BIG(a),n);
        printf("case #%d:\n",i);
       for(int k=R.cnt-1;k>=0;k--)
          printf("%d",R.v[k]);
        printf("\n");
    }

}