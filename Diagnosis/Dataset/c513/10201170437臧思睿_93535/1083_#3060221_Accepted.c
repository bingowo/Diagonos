#include <stdio.h>

int main()
{
    int n=0,N,x,r=0;
    scanf("%d",&N);
    while(n++<N)
    {
        printf("case #%d:\n",n-1);
        scanf("%d",&x);
        r+=x/5+x/25+x/125+x/625;
        printf("%d\n",r);
        r=0;
    }
    return 0;
}
