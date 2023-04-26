#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int isGood(long long n)
{
    if (n%9 == 0){return 0;}
    char s[20];memset(s,0,20*sizeof(char));
    sprintf(s,"%lld",n);
    if (strchr(s,'9')!=NULL){return 0;}
    return 1;
}

int main()
{
    long long a = 0,b = 0;
    scanf("%lld%lld",&a,&b);
    long long i = a;
    int ans = 0;
    for(i = a;i<=b;i++)
    {
        if (isGood(i)){ans++;}
    }
    printf("%d",ans);
    return 0;
}
