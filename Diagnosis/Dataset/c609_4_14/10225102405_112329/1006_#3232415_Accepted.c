#include<stdio.h>
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=0;cas<T;cas++)
    {
        char s[70];scanf("%s",&s);
        int a[128];
        for(int i=0;i<128;i++) a[i]=-1;
        char *p=s;
        a[*p]=1;
        int R=0;
        while(*++p)
        if(a[*p]==-1)
        {
            a[*p]=R;
            R=R?R+1:2;

        }
        if(R<2) R=2;
        p=s;
        long long N=0;
        while(*p) N=N*R+a[*p++];
        printf("case #%d:\n%lld\n",cas,N);
    }
    return 0;
}
