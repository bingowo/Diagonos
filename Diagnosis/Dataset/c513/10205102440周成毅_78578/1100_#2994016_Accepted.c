#include <stdio.h>
#include <string.h>
#define MAXC 110
#define MAXN 100100

char com[MAXC];
int po[MAXN][2];
int pian[MAXC][2];
char chu[][4] = {"No", "Yes"};

void jilu(char *com, int da[][2])
{
    int len = strlen(com);
    int x, y;
    x = y = 0;
    for (int i = 0; i < len; i++)
    {
        if (com[i] == 'U')
            y++;
        else if (com[i] == 'D')
            y--;
        else if (com[i] == 'R')
            x++;
        else if (com[i] == 'L')
            x--;
        da[i][0] = x;
        da[i][1] = y;
    }
}

int panduanda(int x, int y)
{
    if (x == 0 && y == 0)
        return 1;
    int len = strlen(com);
    int dx, dy;
    dx = dy = 0;
    if (pian[len-1][0] == 0 && pian[len-1][1] == 0)
    {
        for (int i = 0; i <= len; i++)
            if (x == pian[i][0] && y == pian[i][1])
                return 1;
        return 0;
    }
    if (pian[len-1][0] == 0)
    {
        int xmin, xmax;
        xmin = xmax = 0;
        for (int i = 0; i < len; i++)
            if (pian[i][0] < xmin)
                xmin = pian[i][1];
            else if (pian[i][0] > xmax)
                xmax = pian[i][0];
        if (x < xmin || x > xmax)
            return 0;
        for (int i = 0; i <= len; i++)
        {
            if ((y - pian[i][1]) % pian[len-1][1] == 0 && x == pian[i][0])
                dy = (y - pian[i][1]) / pian[len-1][1];
            else
                continue;
            if (dy >= 0)
                return 1;
        }
        return 0;
    }
    else if (pian[len-1][1] == 0)
    {
        int ymin, ymax;
        ymin = ymax = 0;
        for (int i = 0; i < len; i++)
            if (pian[i][1] < ymin)
                ymin = pian[i][1];
            else if (pian[i][1] > ymax)
                ymax = pian[i][1];
        //printf("%d %d\n", ymin, ymax);
        if (y < ymin || y > ymax)
            return 0;
        for (int i = 0; i <= len; i++)
        {
            if ((x - pian[i][0]) % pian[len-1][0] == 0 && y == pian[i][1])
                dx = (x - pian[i][0]) / pian[len-1][0];
            else
                continue;
            //printf("%d\n", dx);
            if (dx >= 0)
                return 1;
        }
        //printf("\n");
        return 0;
    }
    else
    {
        for (int i = 0; i <= len; i++)
        {
            if ((x - pian[i][0]) % pian[len-1][0] == 0)
                dx = (x - pian[i][0]) / pian[len-1][0];
            else
                continue;
            if ((y - pian[i][1]) % pian[len-1][1] == 0)
                dy = (y - pian[i][1]) / pian[len-1][1];
            else
                continue;
            if (dx == dy && dx >= 0)
                return 1;
        }
        return 0;
    }
}

int main()
{
    scanf("%s\n", com);
    jilu(com, pian);
    int len = strlen(com);
    int n;
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d\n", &po[i][0], &po[i][1]);
    }
    int state = 1;
    //if (len >= 100)
    //    printf("%d %d\n", po[14154][0], po[14154][1]);
    for (int i = 0; i < n; i++)
    {
        state = panduanda(po[i][0], po[i][1]);
        printf("%s\n",  chu[state]);
    }
    //for (int i = 0; i < strlen(com); i++)
    //    printf("%d %d\n", pian[i][0], pian[i][1]);
    return 0;
}