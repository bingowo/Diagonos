#include<stdio.h>
int main()
{
    int T;
    scanf("%d\n",&T);
    int t=0;
    for(t=0;t<T;t++)
    {
        int m=1,n=1,small=1,large=1,i=1;
        long long int P=1;
        scanf("%d %d\n",&m,&n);
        if(m>2*n)
        {
            small=n;
            large=m-n;
        }
        else
        {
            small=m-n;
            large=n;
        }
        for(i=m;i<large;i--)
        {
            if(i=2*small)
            {
                P=P*2;
                small--;
            }
            else P=P*i;
        }
        while(small>1)
        {
            P/=small;
            small--;
        }
        printf("case #%d:\n",t);
        printf("%lld\n",P);
    }
    return 0;
}