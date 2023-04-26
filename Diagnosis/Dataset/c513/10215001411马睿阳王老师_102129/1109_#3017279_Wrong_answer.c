#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
    int j,i,a,first=0,flag=0,T;//first为第一个非0的位数，flag判断是否为首项
    scanf("%d",&T);
    for(j=0;j<T;j++)
   {
    printf("case #%d:\n",j);
    for(i=8;i>=0;i--)
    {
        scanf("%d",&a);
        if(a&&flag==0) //首项
        {
            flag=1;
            first=i;
        }
        if(first==0&&i==0) printf("%d",a);//只有常数
        if(first!=0&&a!=0)
        {
            //确定符号
            if(a<0) printf("-");
            if(a>0&&i!=first) printf("+");
            //系数
            if((int)fabs(a)!=1||i==0) printf("%d",(int)fabs(a));
            //指数
            if(i>0) printf("x");
            if(i>1) printf("^%d",i);

        }
        printf("\n");
    }
    
   }
    return 0;
}
