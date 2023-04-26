#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int m=1,n=1,small=1,large=1;
        unsigned long long P=1;
        printf("case #%d:\n",i);
        scanf("%d %d",&m,&n);
        if(m>2*n)
        {small=n;large=m-n;}
        else {small=m-n;large=n;}
        for(int j=m;i>large;i--)
        {
            if(i==2*small)
            {P=P*2;small--;}
            else P=P*i;
        }
        while(small>1)
        {
            P=P/small;
            small--;
        }
        printf("%lld\n",P);
    }
    return 0;
}