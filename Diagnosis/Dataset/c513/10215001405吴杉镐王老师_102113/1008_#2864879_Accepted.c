#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int a,b,i=0;
    while(i<n)
    {
        i++;
        int count=0;
        scanf("%d %d",&a,&b);
        int c[32]={'\0'};
        int d[32]={'\0'};
        int n=0,m=0;
        while(a!=0)
        {
            c[n]=a%2;
            n++;
            a=a/2;
        }
        while(b!=0)
        {
            d[m]=b%2;
            m++;
            b=b/2;
        }
        n--;
        m--;
        int i=0,j=0;
        while(i<=n && j<=m)
        {
            if(c[i]!=d[j]) count++;
            i++;
            j++;
        }
        if(n<m)
        {
            while(j<=m)
            {
                if(d[j]!=0) count++;
                j++;
            }
        }
        else
        {
            while(i<=n)
            {
                if(c[i]!=0) count++;
                i++;
            }
        }
        printf("%d",count);
        printf("\n");
    }
}
