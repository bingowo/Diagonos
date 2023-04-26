#include <stdio.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int z=0; z<T; z++)
    {
        int n;
        scanf("%d",&n);
        printf("case #%d:\n",z);
        printf("%d\n",n/5+n/25+n/125+n/625);
    }
}
