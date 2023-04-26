#include <stdio.h>
#include <stdlib.h>
#define N 105
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,i,flag = 0;
        int graph[N][N] = {{0}},out[N] = {0},in[N] = {0};
        scanf("%d",&n);
        for(i = 0;i < n;i++)
        {
            int cmd1,cmd2;
            scanf("%d %d",&cmd1,&cmd2);
            if(!graph[cmd1][cmd2])
            {
                out[cmd1]++;
                in[cmd2]++;
            }
            graph[cmd1][cmd2] = 1;

        }
        for(i = 0;i < N;i++)
        {
            if((out[i] != 0 && in[i] != 0) || out[i] > 2)
            {
                printf("Poor dxw!\n");
                flag = 1;
                break;
            }
            else
                continue;
        }
        if(flag)
            continue;
        printf("Lucky dxw!\n");
    }
    return 0;
}
