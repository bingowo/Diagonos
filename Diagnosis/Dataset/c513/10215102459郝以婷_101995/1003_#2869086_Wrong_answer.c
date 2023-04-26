#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b)
{
    return *(int *)b-*(int *)a;
}

int main()
{
    int T,N,i,j,b[64],m,n,count,c[10][10000],d[10000];
    long long int a[10000];
    scanf("%d ",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d ",&N);
        for(j=0;j<10000;j++)
            {c[i][j]=-1;
            d[j]=-1;}
        for(j=0;j<N;j++)
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
            c[i][j]=count;
            d[j]=count;
        }
    qsort(c[i],j,sizeof(int),cmp);
    for(m=0;m<N;m++)
    {
        for(n=0;n<N;n++)
        {
            if(d[n]==c[i][m])
                {c[i][m]=a[n];
                d[n]=-1;
                a[n]=-1;}
        }
    }
    }
    for(i=0;i<T;i++)
    {
        j=0;
        printf("case #%d:\n",i);
        while(c[i][j]>=0)
        {
            printf("%d ",c[i][j]);
            j++;
        }
        printf("\n");
    }
    return 0;
}
