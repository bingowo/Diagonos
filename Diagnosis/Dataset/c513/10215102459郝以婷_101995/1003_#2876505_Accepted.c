#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,i,j,k,b[64],m,count,d[10000],e[10];//e的长度为10即可
    long long int a[10000],c[10][10000],n;//c和n都得是long long
    scanf("%d ",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d ",&e[i]);
        for(j=0;j<10000;j++)
            {c[i][j]=-1;
            d[j]=-1;}
        for(j=0;j<e[i];j++)
        {
            scanf("%lld",&a[j]);
            m=63;
            count=0;
            for(n=0;n<64;n++)
                b[n]=0;
            if(a[j]>=0)
                n=a[j];
            else
                n=-a[j];
            while (n!=0)
            {
                b[m]=n%2;
                n=n/2;
                m--;
            }
            if(a[j]<0)
            {
                for(m=0;m<64;m++)
                {
                    if(b[m]==1) b[m]=0;
                    else        b[m]=1;
                }
                if(b[63]==1)
                {
                    for(m=63;m>=0;m--)
                    {
                        if(b[m-1]==0)
                        {
                            b[m]=0;b[m-1]=1;break;
                        }
                        else
                            b[m]=0;
                    }
                }
                else
                    b[63]=1;
            }
            for(m=0;m<64;m++)
            {
                if(b[m]==1)   count++;
            }
            //删掉了c[i][j]=count;
            d[j]=count;
        }
        for(j=0;j<e[i]-1;j++)//根据数组d的元素值对数组a中的元素排序，选择排序
        {
           k=j;
           for(m=j+1;m<e[i];m++)
           {
               if(d[m]>d[k])  k=m;
               if(d[m]==d[k])
                  if(a[m]<a[k]) k=m;
           }
           n=d[k];d[k]=d[j];d[j]=n;
           n=a[k];a[k]=a[j];a[j]=n;
     }
        for(j=0;j<e[i];j++) //为c[i]赋值
            c[i][j]=a[j];
    }
    for(i=0;i<T;i++)//输出
    {
        printf("case #%d:\n",i);
        for(j=0;j<e[i];j++)
            printf("%lld ",c[i][j]);
        printf("\n");
    }
    return 0;
}