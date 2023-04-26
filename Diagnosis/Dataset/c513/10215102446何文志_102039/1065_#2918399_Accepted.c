#include <stdio.h>
#include <stdlib.h>
typedef struct Subway
{
    int total[2];//total[0] = ?a, total[1] = ?y
    int in[2];
}subway;
int main()
{
    int a = 0,n = 0,m = 0,x = 0;
    scanf("%d%d%d%d",&a,&n,&m,&x);
    subway sub[21];memset(sub,0,21*sizeof(subway));
    sub[1].total[0] = 1;    sub[1].total[1] = 0;//1a + 0y
    sub[1].in[0]    = 1;    sub[1].in[1]    = 0;//1a + 0y
    sub[2].total[0] = 1;    sub[2].total[1] = 0;//1a + 0y
    sub[2].in[0]    = 0;    sub[2].in[1]    = 1;//0a + 1y
    //sub[3].total[0] = 2;    sub[3].total[1] = 0;//2a + 0y
    //sub[3].in[0]    = 1;    sub[3].in[1]    = 1;//1a + 1y
    for(int i = 3;i<=n;i++)
    {
        sub[i].in[0] = sub[i-1].in[0] + sub[i-2].in[0];
        sub[i].in[1] = sub[i-1].in[1] + sub[i-2].in[1];
        sub[i].total[0] = sub[i-1].total[0] +sub[i-2].in[0];
        sub[i].total[1] = sub[i-1].total[1] +sub[i-2].in[1];
    }

    //for(int i = 1;i<n;i++)
    //{
    //    printf("sub[%d].in = %d*a + %d*y, sub[%d].total = %d*a + %d*y\n"
    //           ,i,sub[i].in[0],sub[i].in[1],i,sub[i].total[0],sub[i].total[1]);
    //}
    sub[n].total[0] = sub[n-1].total[0];
    sub[n].total[1] = sub[n-1].total[1];
    sub[n].in[0] = 0;sub[n].in[1] = 0;
    int y = 0;
    y = (m-sub[n].total[0]*a)/sub[n-1].total[1];

    int ans = 0;
    ans = sub[x].total[0]*a + sub[x].total[1]*y;
    //printf("y = %d\n",y);
    printf("%d\n",ans);
    return 0;
}
