#include <stdio.h>
#include <stdlib.h>

//int cmp(const void *a,const void *b)
//{
//    return *(int *)b-*(int *)a;
//}

int main()
{
    int T,N,i,j,b[64],m,count,d[10000],e[10],max,temp;
    long long int a[10000],n,c[10][10000];
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
                    if(b[m]==1)
                        b[m]=0;
                    else
                        b[m]=1;
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
                if(b[m]==1)
                    count++;
            }
            //c[i][j]=count;//删除
            d[j]=count;
        }
    //qsort(c[i],j,sizeof(int),cmp);//删除
//    for(j=0;j<e[i];j++)
//    {
//        min=j;
//        for(m=j+1;m<e[i];m++)
//        {
//            if(d[m]==d[j])
//            {
//                if(a[m]<a[min])
//                {
//                    min=m;
//                    if(min!=j)
//                    {
//                        temp=a[j];
//                        a[j]=a[min];
//                        a[min]=temp;
//                    }
//                }
//            }
//        }
//    }
//    for(m=0;m<e[i];m++)
//    {
//        for(n=0;n<e[i];n++)
//        {
//            if(d[n]==c[i][m])
//                {c[i][m]=a[n];
//                d[n]=-1;
//                a[n]=-1;
//                break;}
//        }
//    }
    for(j=0;j<e[i]-1;j++)
    {
        max=j;
        for(m=j+1;m<e[i];m++)
        {
            if(d[m]>d[max])
                max=m;
            if(d[m]==d[max])
                if(a[m]<a[max])
                    max=m;
        }
        temp=d[m];
        d[m]=d[max];
        d[max]=temp;
        temp=a[m];
        a[m]=a[max];
        a[max]=temp;
    }
    for(j=0;j<e[i];j++)
        c[i][j]=a[j];
    }
    for(i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        for(j=0;j<e[i];j++)
            printf("%lld ",c[i][j]);
        printf("\n");
    }
    return 0;
}
