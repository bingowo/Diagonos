#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int n;
    scanf("%d",&n);
    long long int a[1000];
    long long int b[100000];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    a[n]='\0';
    for(int i=0;i<n;i++)
    {
        int j=0;
        for(;a[i]>0;a[i]/=2333)
        {
            b[j++]=a[i]%2333;
        }
        b[j]='\0';
        for(int p=j-1;p>=0;p--)
        {

            if(p==0)
                printf("%lld\n",b[p]);
            else printf("%lld ",b[p]);
        }
    }
    return 0;
}