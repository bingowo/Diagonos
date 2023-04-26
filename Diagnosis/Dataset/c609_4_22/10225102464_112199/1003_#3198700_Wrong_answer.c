#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[1000];
    int b[1000];
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
                printf("%d\n",b[p]);
            else printf("%d ",b[p]);
        }
    }
    return 0;
}