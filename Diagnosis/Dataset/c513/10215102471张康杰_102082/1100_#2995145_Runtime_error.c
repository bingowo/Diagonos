#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char move[101];
    scanf("%s",&move);
    int T,i,len;
    len = strlen(move);
    int point[len + 1][2],move_x,move_y;
    scanf("%d",&T);
    for(i = 0;i < T;i++)
    {
        int a,b,j,flag = 0;
        scanf("%d %d",&a,&b);
        point[0][0] = a,point[0][1] = b;
        for(j = 1;j < len + 1;j++)
        {
            if(move[j] == 'L')
            {
                point[j][0] = point[j - 1][0] - 1;
                point[j][1] = point[j - 1][1];
                move_x--;
            }
            else if(move[j] == 'R')
            {
                point[j][0] = point[j - 1] + 1;
                point[j][1] = point[j - 1][1];
                move_x++;
            }
            else if(move[j] == 'U')
            {
                point[j][0] = point[j - 1][0];
                point[j][1] = point[j - 1][1] + 1;
                move_y++;
            }
            else if(move[j] == 'D')
            {
                point[j][0] = point[j - 1][0];
                point[j][1] = point[j - 1][1] - 1;
                move_y--;
            }
        }
        for(j = 0;j < len + 1;j++)
        {
            if(point[j][0] == a && point[j][1] == b)
            {
                flag = 1;
                break;
            }
        }
        for(j = 0;j < len + 1;j++)
        {
            int remain_x = a - point[j][0] % move_x;
            int remain_y = b - point[j][1] % move_y;
            if(remain_x == 0 && remain_y == 0 && remain_x == remain_y)
            {
                flag = 1;
                break;
            }
        }
        if(flag)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}