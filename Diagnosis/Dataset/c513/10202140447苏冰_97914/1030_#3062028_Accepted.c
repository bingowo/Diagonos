#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
typedef struct SSS
{
    long long value;
    int single;
}sss;
int cmp(const void*_a,const void*_b)
{
    sss* a=(sss*)_a;
    sss* b=(sss*)_b;
    if(a->single != b->single) return b->single - a->single;
    else return a->value > b->value ? 1 : -1;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=0;cas<T;cas++)
    {
        int n;
        scanf("%d",&n);
        sss s[n];
        char x[20];
        for(int i=0;i<n;i++)
        {
            scanf("%s",x);
            int k=0;
            if(x[0]=='-') k=1;
            s[i].single=x[k]-'0';
            long long ans=0;
            for(int j=k;j<strlen(x);j++)
            {
                ans=ans*10+x[j]-'0';
            }
            s[i].value=ans;
            if(k==1) s[i].value=ans*(-1);
        }
        qsort(s,n,sizeof(sss),cmp);
        printf("case #%d:\n",cas);
        for(int i=0;i<n-1;i++)
        {
            printf("%lld ",s[i].value);
        }
        printf("%lld\n",s[n-1].value);
    }
    return 0;
}
