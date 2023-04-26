#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int main()
{
    int n=0;
    scanf("%d",&n);
    char a[n][10000];
    for(int i=0;i<n;i++)
        scanf("%s",a[i]);
    long long num;
    for(int i=0;i<n;i++)
    {
        num=0;
        for(int p=0;p<strlen(a[i]);p++)
        {
            num+=a[i][p]=='-'?-1:a[i][p]-48;
            if(p<strlen(a[i])-1)num*=3;
        }
        printf("case #%d\n",i);
        printf("%lld\n",num);
    }
    return 0;
}
