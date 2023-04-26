#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    long long n;
    char a[30];
    scanf("%lld",&n);
    int f1=0,f2=0;
    while(1)
    {
        n++;
        if(n%9!=0)
            f1=1;
        int j=0;
        int i=0;
        sprintf(a,"%lld",n);
        for(i=0;i<strlen(a);i++)
        {
            f2=1;
            if(a[i]=='9')
            {
                f2=0;
                break;
            }
        }
        if(f1==1&&f2==1)
            break;
    }
    printf("%lld",n);
    return 0;
}