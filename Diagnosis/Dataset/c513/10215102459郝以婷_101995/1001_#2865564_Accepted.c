#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,a[100],b[100],i=0,m,n,j,p;
    char t,c[100];
    scanf("%d",&T);
    while(i<T)
    {
        scanf("%d %d",&a[i],&b[i]);
        i++;
    }
    for(i=0;i<T;i++)
    {
        j=0;
        if(a[i]<0)
            n=-a[i];
        else
            n=a[i];
        while(n!=0)
        {
            m=n%b[i];
            if(m>=10)
            {
                t=m-10+65;
                c[j]=t;
            }
            else
                c[j]=m+48;
            j++;
            n=n/b[i];
        }
        if(a[i]<0)
            printf("-");
        for(p=j-1;p>=0;p--)
            printf("%c",c[p]);
        printf("\n");
    }
    return 0;
}
