#include <stdlib.h>
#include <stdio.h>

typedef struct 
{
    int known,unknown;
}CROWD;

CROWD add(CROWD S,CROWD T);

int main()
{
    int a,n,m,x;
    int unknown;
    scanf("%d %d %d %d",&a,&n,&m,&x);
    CROWD up[21] = {{0,0}},down[21] = {{0,0}},total[21] = {{0,0}};
    up[1].known = a,up[1].unknown = 0,total[1].known = a;
    up[2].unknown = 1,down[2].unknown = 1,total[2].known = a;
    for(int i = 3;i <= n - 1;i++)
    {
        up[i] = add(up[i - 1],up[i - 2]);
        down[i] = up[i - 1];
        total[i] = add(total[i - 1],up[i - 2]);
    }
    unknown = (m - total[n - 1].known) / total[n - 1].unknown;
    printf("%d",total[x].known + total[x].unknown * unknown);
    return 0;
}

CROWD add(CROWD S,CROWD T)
{
    CROWD R;
    R.known = S.known + T.known;
    R.unknown = S.unknown + T.unknown;
    return R;
}