#include <stdio.h>

int main()
{
    int cas; scanf("%d",&cas);
    for(int i=0;i<cas;i++)
    {
        int m,n,small,large;
        unsigned long long P=1;
        scanf("%d %d",&m,&n);
        if(m-n>n) {small=n; large=m-n;}
        else {small=m-n; large=n;}
        for(int j=m;j>large;j--)
            if(j==2*small) {P*=2;small--;}
            else P*=j;
        while(small>1) {P/=small;small--;}
        printf("case #%d:\n",i);
        printf("%lld\n",P);
    }
    return 0;
}
