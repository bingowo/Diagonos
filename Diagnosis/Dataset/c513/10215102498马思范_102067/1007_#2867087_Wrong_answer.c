#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    long long int b;
    int c[100];
    scanf("%d",&a);
    for(int j=0;j<a;j++)
    {
        int i=0;
        scanf("%lld",&b);
        while(b!=0)
        {
            c[i]=b%2;
            b=b/2;
            i++;
        }
        int m[10];
        for(int r=0;r<10;r++)
        {
            m[r]=0;
        }
        int q=0;
        for(int k=i;k>0;k--)
        {
            if(c[k]!=c[k-1])
                m[q]++;
            else
                q++;
        }
        int max=m[0];
        for(int p=1;p<q;p++)
        {
            if(m[p]>max)
                max=m[p];
        }
        printf("case #%d:",j);
        printf("\n");
        printf("%d",max);
        printf("\n");
    }
    return 0;

}