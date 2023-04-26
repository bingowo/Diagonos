#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long int LLD;

int main()
{
    char move[101];
    scanf("%s",&move);
    int T,i,len;
    len = strlen(move);
    LLD point[len + 1][2],move_x = 0,move_y = 0;
    point[0][0] = 0,point[0][1] = 0;
    for(i = 1;i < len + 1;i++)
    {
        if(move[i - 1] == 'L')
        {
            point[i][0] = point[i - 1][0] - 1;
            point[i][1] = point[i - 1][1];
            move_x--;
        }
        else if(move[i - 1] == 'R')
        {
            point[i][0] = point[i - 1][0] + 1;
            point[i][1] = point[i - 1][1];
            move_x++;
        }
        else if(move[i - 1] == 'U')
        {
            point[i][0] = point[i - 1][0];
            point[i][1] = point[i - 1][1] + 1;
            move_y++;
        }
        else if(move[i - 1] == 'D')
        {
            point[i][0] = point[i - 1][0];
            point[i][1] = point[i - 1][1] - 1;
            move_y--;
        }
    }
    scanf("%d",&T);
    for(i = 0;i < T;i++)
    {
        LLD a,b,j,flag = 0;
        scanf("%lld %lld",&a,&b);
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
            if(flag == 1)
                break;
            int remain_x = 1,remain_y = 1;
            int steps_x,steps_y;
            LLD orient_x,orient_y;
            if(move_x != 0)
            {
                remain_x = (a - point[j][0]) % move_x;
                steps_x = (a - point[j][0]) / move_x;
                orient_x = (a - point[j][0]) * move_x;
            }
            else
            {
                for(j;j < len + 1;j++)
                {
                    if(point[j][0] == a)
                    {
                        remain_x = 0;
                        orient_x = 0;
                        break;
                    }
                }
            }
            if(remain_x != 0)
            {
                continue;
            }
            if(move_y != 0)
            {
                remain_y = (b - point[j][1]) % move_y;
                steps_y = (b - point[j][1]) / move_y;
                orient_y = (b - point[j][1]) * move_y;
            }
            else
            {
                for(j;j < len + 1;j++)
                {
                    if(point[j][1] == b)
                    {
                        remain_y = 0;
                        orient_y = 0;
                        break;
                    }
                }
            }
            if(move_y == 0 || move_x == 0)
                steps_x = steps_y;
            if(remain_x == 0 && remain_y == 0)
            {
                if(steps_x == steps_y)
                {
                    if(orient_x >= 0 && orient_y >= 0)
                    {
                        flag = 1;
                        break;
                    }
                    else
                    {
                        continue;
                    }
                }
                else
                {
                    continue;
                }
            }
        }
        if(flag)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}