#include <stdio.h>
int diflong(int n)
{
    int s[32],i,j,a;
    while(n)
    {
        i=0;
        s[i]=n%2;
        i++;
        n=n/2;
    }
    int mlen=1;
    for(a=1,j=1;a<i;a++)
    {
        if(s[a]!=s[a-1]) j++;
        else
        {
            if(s[i]==0)
            {
                j=0;
                continue;
            }
            else j=1;
        }
        if(mlen<j) mlen=j;
    }
    return mlen;
}
int main()
{
    int T,a,n,b;
    scanf("%d\n",&T);
    for(a=0;a<T;a++)
    {
        scanf("%d\n",&n);
    }
    for(b=0;b<T;b++)
    {
        printf("case #%d:",b);
        printf("\n");
        printf("%d",diflong(n));
        printf("\n");
    }
    return 0;
}
