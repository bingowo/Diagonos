#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{long long x,y,len;}point;

int cmp(const void*a,const void*b)
{
    point c = *(point*)a;
    point d = *(point*)b;
    if(c.len < d.len)
    {
        if(c.len < 0)return -1;
        else return 1;
    }
    else if(c.len > d.len)
    {
        if(d.len < 0)return 1;
        else return -1;
    }
    else if(c.x < d.x)return -1;
    else if(c.x > d.x)return 1;
    else if(c.y < d.y)return -1;
    else return 1;
}
int main()
{
    int cas,i;
    long long d,distance,r,ans,r1,r2,dx,dy;
    point *s;
    scanf("%d",&cas);
    s = (point*)malloc(cas*sizeof(point));
    for(i = 0; i < cas; i++)
    {
        scanf("%lld %lld",&s[i].x,&s[i].y);
        dx = llabs(s[i].x);
        dy = llabs(s[i].y);
        s[i].len = dx + dy;
        //printf("%lld\n",s[i].len);
    }
    qsort(s,cas,sizeof(s[0]),cmp);
    for(i = 0; i < cas; i++)printf("%lld %lld\n",s[i].x,s[i].y);
    dx = llabs(s[0].x - s[1].x);
    dy = llabs(s[0].y - s[1].y);
    distance = dx + dy;
    if(dx > distance)
        printf("18446744073709551615\n");
    else
        printf("%lld\n",distance);
    for(i = 1,ans = 0; i < cas; i++)
    {
        dx = llabs(s[i].x - s[i-1].x);
        dy = llabs(s[i].y - s[i-1].y);
        if((dx%2 == 0 && dy%2 == 0)||(dx%2 == 1 && dy%2 == 1))break;
        else if(dx < 0)
        {
            ans += 64;
        }
        else
        {
            if(dx == 0)r1 = 0;
            if(dy == 0)r2 = 0;
            if(dx != 0)
            {
               for(r1 = 1; r1 < 63; r1++)
               {
                  if(pow(2,r1-1) <= dx&&pow(2,r1) >= dx)break;
               }
            }
            if(dy != 0)
            {
               for(r2 = 1; r2 < 63; r2++)
               {
                  if(pow(2,r2-1) <= dy&&pow(2,r2) >= dy)break;
               }
            }
            r = r1>r2?r1:r2;
            if(r1 == r2)r++;
            else if(abs(r1-r2) == 1)
            {
                if(r1 > r2)
                {
                    dy /= 2;
                    if(dy + dx > 2)r++;
                }
                if(r1 < r2)
                {
                    dx /= 2;
                    if(dy + dx > 2)r++;
                }
            }
            ans += r;
        }
    }
    printf("%lld",ans);
    return 0;
}
