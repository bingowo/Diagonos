#include<stdio.h>
#include<stdlib.h>

int CountBin1(long long a)// 统计a对应的二进制数中1的个数
{
    int b[64],n=0,x,i,j;
    if(a<0)
    {
        x=-a;
    }
    else
    {
        x=a;
    }
    i=63;
    while(x!=0)//将x转换为二进制数存放到数组b
    {
        b[i]=x%2;
        x=x/2;
        i--;
    }
    for(j=0;j<=i;j++)//将数组b的其他位置0
        b[j]=0;
    if(a<0)
    {
        for(j=0;j<64;j++)//求反
        {
            if(b[j]==0)
                b[j]=1;
            else
                b[j]=0;

        }
        for(j=63;j>=0;j--)//加1
        {
            if(b[j]==1)
                b[j]=0;
            else
            {
                b[j]=1;
                break;
            }
        }
    }
    for(j=0;j<=64;j++)//统计1的个数
        if(b[j]==1) n=n+1;
//通过二进制位运算统计1的个数，可以替换掉前面的程序
//    int i,n;
//    for(i=0;i<64;i++)
//    {
//        if(a&1==1) n=n+1;
//        a=a>>1;
//    }
    return n;
}

long long* bin_sort(long long a[], int N)//根据1的个数对数组a中的元素排序
{
    int b[N],i,j,k;
    long long t;
    for(i=0;i<N;i++)//计算a[i]对应的二进制数的1的个数，存放到b[i]中
    {
        b[i]=CountBin1(a[i]);
    }
    for(i=0;i<N-1;i++)//根据数组b的元素值对数组a中的元素排序，选择排序
    {
        k=i;
        for(j=i+1;j<N;j++)
        {
            if(b[j]>b[k])  k=j;
            if(b[j]==b[k])
                if(a[j]<a[k])
                    k=j;

        }
        t=b[k];b[k]=b[i];b[i]=t;
        t=a[k];a[k]=a[i];a[i]=t;
 }
    return a;
}


int main()
{
    int T,N[10],i,j;//数组N用来存放T个问题中输入整数的个数N
    long long *a,*b[10];//指针变量a指向N个数的空间，b是一个指针数组,每个数组元素指向一个已经排好序的一维数组
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d",&N[i]);
        a=(long long*)malloc(N[i]*sizeof(long long));
        for(j=0;j<N[i];j++)
        {
            scanf("%lld",&a[j]);
        }
        b[i]=bin_sort(a,N[i]);
    }
    for(i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        for(j=0;j<N[i];j++)
            printf("%lld ",*(b[i]+j));
        printf("\n");
    }
    free(a);
    return 0;
}