#include <stdio.h>
#include <string.h>
int diflong(int n)
{
    int s[32],i,j;
    while(n)
    {
        i=0;
        s[i]=n%2;
        n=n/2;
        i++;
    }
    int mlen=1;
    for(i=1,j=1;i<strlen(s);i++)
    {
        if(s[i]!=s[i-1])
        {
            j++;
            if(j>mlen) mlen=j;
        }
        else j=1;
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
