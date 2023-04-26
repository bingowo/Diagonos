#include <stdio.h>
#include <stdlib.h>

void solve()
{
    char s[61]; scanf("%s",s);
    int a[128]; for(int i=0;i<128;i++) a[i]=-1;
    int R=0;
    char *p=s;
    a[*p]=1;
    while (*++p)
        if(a[*p] == -1)
        {
            a[*p]=R;
            R=R? (R+1):2;
        }
    if(R<2) R=2;
    long long int N=0;
    p=s;
    while(*p)
        N=N*R+a[*p++];
    printf("%lld\n",N);
}


int main()
{
    int T;
    scanf("%d",&T);
    for(int cnt=0;cnt<T;cnt++)
    {
        printf("case #%d:\n",cnt);
        solve();
    }
    return 0;
}