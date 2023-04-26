#include <stdio.h>
#include <stdlib.h>

int main()
{
    struct ww
    {
        int x;
        int y;
    };
    int t,T;
    scanf("%d",&T);
    for(t=0;t<T;t++)
    {
        int n,i,go=0,con=0,a,b,lo=0,j;
        scanf("%d",&n);
        int w1[100]={0},w2[100]={0};
        for(i=0;i<n;i++)
            {
                scanf("%d%d",&a,&b);
                for(j=0;j<lo;j++)
                {
                    go=0;
                    con=0;
                    if(a==b||(a==w1[j]&&b==w2[j]))
                    {
                        con=1;
                        break;
                    }
                    if(a==w1[j])
                    {
                        go=1;
                        break;
                    }
                    if(a==w2[j]||b==w1[j])
                    {
                        go=1;
                        break;
                    }
                }
                if(con)
                    continue;
                if(go==0)
                {
                    w1[lo]=a;
                    w2[lo]=b;
                    lo++;
                }
                if(go)
                    break;
            }
        i++;
        for(;i<n;i++)
            scanf("%d%d",&a,&b);
        if(go)
            printf("Poor dxw!\n");
        else
            printf("Lucky dxw!\n");
    }
    return 0;
}
