#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    int a[100]={0};
    for(int cas=0;cas<T;cas++)
    {
        char s[100];
        scanf("%s",s);
        char *p=s;
        while(*p)
        {
            if(*p=='0') a[*p]=0;
            if(*p=='-') a[*p]=-1;
            if(*p=='1') a[*p]=1;
            p++;
        }
        long long N=0;
        p=s;
        while(*p) {N=N*3+a[*p];}
        printf("case #%d:\n%lld\n",cas,N);
    }
    return 0;
}
