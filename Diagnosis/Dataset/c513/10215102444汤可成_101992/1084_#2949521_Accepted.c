#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T = 0;
    scanf("%d", &T);
    int i = 0;
    for(i = 0; i<T; i++)
    {
        int N = 0;
        scanf("%d", &N);
        printf("case #%d:\n", i);
        long num = 1;
        if(i == 0) printf("1\n");
        else
        {
            for(int j = 0; j<N; j++)
            {
                num *= 2;
            }
            printf("%ld\n", num);
        }
    }
    return 0;
}
