#include <stdio.h>

int main()
{
    unsigned long long m,n,small,large;
    unsigned long long P=1;
    int cas; scanf("%d",&cas);
    for(unsigned long long i=0;i<(unsigned long long)cas;i++)
    {
        scanf("%lld %lld",&m,&n);
        if(m-n>n) {small=n; large=m-n;}
        else {small=m-n; large=n;}
        for(unsigned long long j=m;j>large;j--)
            if(j==2*small) {P=P*2;small--;}
            else P=P*j;
        while(small>1) {P=P/small;small--;}
        printf("case #%d:\n",i);
        printf("%lld\n",P);
    }
    return 0;
}
