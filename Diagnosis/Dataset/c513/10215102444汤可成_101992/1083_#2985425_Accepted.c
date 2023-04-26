#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T = 0;
    scanf("%d",&T);
    int i = 0;
    for(i = 0;i<T; i++)
    {
        int n = 0;
        scanf("%d", &n);
        int ret = 0;
        int five = 5;
        while(n>=five)
        {
            ret += n/five;
            five = five*5;
        }
        printf("case #%d:\n", i);
        printf("%d\n", ret);
    }
    return 0;
}
