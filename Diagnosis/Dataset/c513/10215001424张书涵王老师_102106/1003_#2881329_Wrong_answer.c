#include <stdio.h>
#include <stdlib.h>

void yigeshu(char*c,int b)
{
    int i;
    b=0;
    for(i=0;i<64;i++)
    {
        if(c[i]=='1')
            b=b+1;
    }
}

void erjinzhi(char* c,int n)
{
    int i;
    if(n<0)
    {
        n=(-1)*n;
        for(i=0;i<64;i++)
        {
            c[i]=n%2+48;
            n=n/2;
            if(c[i]=='0')
                c[i]='1';
            else
                c[i]='0';
        }
        c[0]=c[0]+1;
        for(i=0;c[i]=='2';i++)
        {
            c[i]='0';
            c[i+1]=c[i+1]+1;
        }
    }
    else
    {
        for(i=0;i<64;i++)
        {
            c[i]=n%2+48;
            n=n/2;
        }
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    int i;
    for(i=0;i<T;i++)
    {
        int t,j;
        scanf("%d",&t);
        int a[t];
        int b[t];   //b存储的是a数字二进制中的1的个数
        char c[t][64];
        for(j=0;j<t;j++)
        {
            scanf("%d",&a[j]);  //a存储的是数字
            erjinzhi(c[j],a[j]);
            yigeshu(c[j],b[j]);
        }
        int m,n,k;
        for(m=0;m<t;m++)
        {
            for(n=0;n<t;n++)
            {
                if(b[m]<b[n])
                {
                    k=a[m];
                    a[m]=a[n];
                    a[n]=k;
                }

            else
            {
                if(b[m]==b[n])
                {
                    if(a[m]>a[n])
                        {
                            k=a[m];
                            a[m]=a[n];
                            a[n]=k;
                        }
                }
            }
        }}
        int l;
        printf("case #%d\n",i);
        for(l=0;l<t;l++)
            printf("%d ",a[l]);
    }
    return 0;
}
