#include<stdio.h>
#include<string.h>

int max(int a,int b)
{
    if(a>b) return a;
    else return b;
}

int main()
{
    int T,i;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        int c[107][107];
        int a,j=0,k,m,n,l[107],t[1007],z;
        char p;
        scanf("%d",&a);
        while(a)
        {
            t[j++]=a%2;
            a/=2;
        }
        k=j;
        if(k==1)
        {
             printf("case #%d:\n",i);
             printf("1\n");
        }
        else
        {
            for(j=0;j<=(k-1)/2;j++)
            {
                p=t[j];
                t[j]=t[k-j-1];
                t[k-j-1]=p;
            }
            c[0][0]=t[0];
            n=0;m=1;
            for(j=1;j<k;j++)
            {
                if(t[j]==t[j-1])
                {
                    l[n]=m;
                    m=1;
                    n++;
                    c[n][0]=t[j];
                }
                else if(t[j]!=t[j-1])
                {
                    c[n][m]=t[j];
                    m++;
                    l[n]=m;
                }
            }
            z=max(l[0],l[1]);
            for(j=2;j<=n;j++)
            {
                if(l[j]>z) z=l[j];
            }
            printf("case #%d:\n",i);
            printf("%d\n",z);
        }
    }
    return 0;
}
