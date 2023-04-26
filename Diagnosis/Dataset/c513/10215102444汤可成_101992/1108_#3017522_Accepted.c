#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T = 0;
    scanf("%d", &T);
    int i = 0;
    for(i = 0; i<T; i++)
    {
        int q[100] = {0};
        int status[100] = {0};
        int flag = 0, m, n;
        scanf("%d %d", &n, &m);
        printf("case #%d:\n0.", i);

        for(int j = 1; !flag; j++)
        {
            if(n == 0)//整除
            {
                printf("\n");
                flag = 1;
            }
            else
            {
                if(status[n])//循环
                {
                    flag = 1;
                    printf("\n");
                    printf("%d-%d\n", status[n], j-1);
                }
                else
                {
                    status[n] = j;
                    q[j] = n*10/m;
                    printf("%d", q[j]);
                    n = n*10%m;
                }
            }
        }

    }
    return 0;
}
