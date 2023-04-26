#include <stdio.h>
#include <string.h>
const int N = 111;
int dx[N] = {0},dy[N] = {0};
char order[N];
int walk(int ab,int dxy,int dis_xy)
{
    if(dis_xy > 0 && ab >= dxy && (ab - dxy) % dis_xy == 0)
        return (ab - dxy) / dis_xy;
    else if(dis_xy < 0 && ab <= dxy && (ab - dxy) % dis_xy == 0)
        return (ab - dxy) / dis_xy;
    else if(dis_xy == 0 && ab == dxy)
        return -2;
    else
        return -1;
}
int main(void)
{
    scanf("%s",order);
    int len=strlen(order);
    dx[0] = 0;
    dy[0] = 0;
    for(int i = 1; i <= len; i++)
    {                              
        dx[i] = dx[i-1];
        dy[i] = dy[i-1];
        switch(order[i-1])
        {
        case 'U':
            dy[i]++;
            break;
        case 'D':
            dy[i]--;
            break;
        case 'L':
            dx[i]--;
            break;
        case 'R':
            dx[i]++;
            break;
        }
    }
    int dis_x = dx[len];
    int dis_y = dy[len];
    int __;
    scanf("%d",&__);
    for(int _ = 0,a,b; _<__; _++) 
    {                             
        scanf("%d %d",&a,&b);
        int ans = 0;
        for(int i = 0;i <= len; i++)
        {
            ans = 0;
            int can_reach_a = walk(a,dx[i],dis_x);
            int can_reach_b = walk(b,dy[i],dis_y);
            if(can_reach_a == -1 || can_reach_b == -1)
                ans = 0;
            else if(can_reach_a == -2 || can_reach_b == -2)
                ans = 1;
            else if(can_reach_a == can_reach_b)
                ans = 1;
            else
                ans = 0;
            if(ans)
                break;
        }
        if(ans)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}