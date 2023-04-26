#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{
    char w[1001];
    scanf("%s",w);
    int len= strlen(w);
    int x=0;//记录3
    int y=0;//记录2
    if(len==1)
        printf("%d",1);
    else if(len==2)
    {
        if(w[0]==w[1])
            printf("%d",1);
        else
            printf("%d",4);
    }
    else
    {
        if (w[0] != w[1])
            y++;
        if (w[len - 1] != w[len - 2])
            y++;
        for (int i = 1; i < len - 1; i++) {
            if (w[i] != w[i + 1] && w[i] != w[i - 1] && w[i - 1] == w[i + 1])
                y++;
            else if (w[i] != w[i + 1] && w[i] != w[i - 1] && w[i - 1] != w[i + 1])
                x++;
            else if (w[i] == w[i - 1] && w[i] != w[i + 1])
                y++;
            else if (w[i] == w[i + 1] && w[i] != w[i - 1])
                y++;
        }
        if (x == 0 && y == 0)
            printf("%d", 1);
        else
        {
            long long r1, r2, r;
            r1 = pow(2, y);
            r2 = pow(3, x);
            r = ((r1 % 1000000007) * (r2 % 1000000007)) % 1000000007;
            printf("%lld", r);
        }
    }
    return 0;
}