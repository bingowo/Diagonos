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
}
int main()
{
    int T,i,n,j;
    scanf("%d\n",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d\n",&n);
    }
    for(j=0;j<T;j++)
    {
        printf("case #%d:",j);
        printf("\n");
        printf("%d",diflong(n));
        printf("\n");
    }
    return 0;
}
