#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{int x,y;}point;

int func(int x,int px,int dx)
{
    if(dx == 0 && x == px)return 2;
    else if(dx > 0 && x > px && (x-px)%dx == 0)return (x-px)/dx;
    else if(dx < 0 && x < px && (x-px)%dx == 0)return (x-px)/dx;
    else return -1;
}

int main()
{
    int i,j,cas,a,b;
    char s[107];
    scanf("%s",s);
    point p[107];
    int len = strlen(s);
    //p = (point*)malloc(len*sizeof(point));
    p[0].x = 0;p[0].y = 0;
    for(i = 1; i <= len; i++)
    {
        p[i].x = 0;p[i].y = 0;
        switch(s[i-1])
        {
            case 'U':p[i].x = p[i-1].x;p[i].y = p[i-1].y+1;break;
            case 'D':p[i].x = p[i-1].x;p[i].y = p[i-1].y-1;break;
            case 'L':p[i].x = p[i-1].x-1;p[i].y = p[i-1].y;break;
            case 'R':p[i].x = p[i-1].x+1;p[i].y = p[i-1].y;break;
        }
    }
    scanf("%d",&cas);
    int flag,ans1,ans2;
    for(i = 0; i < cas; i++)
    {
        scanf("%d%d",&a,&b);
        //printf("%d %d\n",a,b);
        for(j = 0; j <= len; j++)
        {
            ans1 = func(a,p[j].x,p[len].x);
            ans2 = func(b,p[j].y,p[len].y);
            if(ans1 == ans2 && ans1 != -1){flag = 1;break;}
            else if(ans1 == 2 || ans2 == 2){flag = 1;break;}
            else if(ans1 = -1 || ans2 == -1){flag = 0;}//直接排除所有x，y拒绝不能够达到要求的情况；
        }
          if(flag == 0)printf("No\n");
          else printf("Yes\n");
          //printf("%d\n",flag);
    }
    return 0;
}