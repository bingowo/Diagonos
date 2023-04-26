#include <stdio.h>
int main()
{
    int s[32],i,a,T,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d\n",&n);
        while(n)
        {
            i=0;
            s[i]=n%2;
            i++;
            n=n/2;
        }
        int mlen=1,j=1;
        for(a=1;a<i;a++)
        {
            if(s[a]!=s[a-1])
            {
                j++;
                if(j>mlen) mlen=j;
            }
            else j=1;
        }
        int b=0;
        printf("case #%d:",b++);
        printf("\n");
        printf("%d",mlen);
        printf("\n");
        s[32]=0;
    }
    return 0;
}
