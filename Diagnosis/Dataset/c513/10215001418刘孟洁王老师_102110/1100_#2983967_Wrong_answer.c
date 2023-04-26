#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{int x,y;}point;

int main()
{
    int i,j,cas,a,b,k;
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
    int flag,n1,n2,n;
    for(i = 0; i < cas; i++)
    {
        scanf("%d%d",&a,&b);
        if(p[len].x && p[len].y)
        {
           if(p[len].x)n1 = a/p[len].x;
           if(p[len].y)n2 = b/p[len].y;
           n = n1<n2 ? n1:n2;
           a = a - n*p[len].x;
           b = b - n*p[len].x;
        }
        else
        {
            if(p[len].x == 0 && p[len].y)
            {
                n = b/p[len].y;
                b = b - n*p[len].y;
            }
            if(p[len].y == 0 && p[len].x)
            {
                n = a/p[len].x;
                a = a - n*p[len].x;
            }
        }
        for(j = 0; j <= len; j++)
        {
            flag = 0;
            if(a == p[j].x && b == p[j].y){flag = 1;break;}
        }
          if(flag == 0)printf("No\n");
          else printf("Yes\n");
          //printf("%d\n",flag);
    }
    return 0;
}

