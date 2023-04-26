#include <stdio.h>

int main()
{
    int m=1,n=1,small, large;
    unsigned long long P=1;
    int cas; scanf("%d",&cas);
    for(int i=0;i<cas;i++)
    {
        scanf("%d %d",&m,&n);
        if(m-n>n) {small=n; large=m-n;}
        else {small=m-n; large=n;}
        for(int j=m;j>large;j--)
            if(j==2*small) {P=P*2;small--;}
            else P=P*j;
        while(small>1) {P=P/small;small--;}
        printf("case #%d:\n",i);
        printf("%llu\n",P);
    }
    return 0;
}
