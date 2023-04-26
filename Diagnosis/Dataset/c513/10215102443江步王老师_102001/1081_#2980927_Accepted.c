#include<stdio.h>

int mul(int *res,int a,int num);
int main()
{
    int i,j;
    int t;
    int a,n;
    int res[101];
    
    scanf("%d",&t);

    for (i=0;i<t;i++)
    {
        int num=1;
        scanf("%d %d",&a,&n);
        //初始化res数组
        res[0]=1;
        for (j=1;j<101;j++)
        {
            res[j]=0;
        }

        //进行乘方运算，将n次方拆分成n次乘法
        for (j=0;j<n;j++)
        {
            num=mul(res,a,num);
        }

        //输出结果
        printf("case #%d:\n",i);
        for (j=num-1;j>=0;j--)
        {
            printf("%d",res[j]);
        }
        putchar('\n');
    }
    return 0;
}

//mul函数的作用,实现高精度乘法运算并返回位数
int mul(int *res,int a,int num)
{
    int i;
    int c=0;
    
    for (i=0;i<num;i++)
    {
        int t=res[i]*a+c;
        c=t/10;
        res[i]=t%10;
    }

    if (c!=0)
    {
        res[num++]=c;
    }

    return num;
}