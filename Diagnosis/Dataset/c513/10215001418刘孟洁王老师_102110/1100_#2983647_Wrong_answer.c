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
    for(i = 0; i < cas; i++)
    {
        scanf("%d%d",&a,&b);
        //if(a == 0 && b == 0){printf("Yes\n");continue;}
        //if(a%p[len].x == 0 && b%p[len].y == 0){printf("Yes\n");continue;}
        /*else
        {
            while(a>=p[len].x && b>=p[len].y)
            {
             a -= p[len].x;
             b -= p[len].y;
            }*/
           for(j = 0; j <= len; j++)
           {
            if(a == p[j].x && b == p[j].y)break;
            else
            {
                for(k = 1; k<100; k++)
                if(a == k*p[len].x+p[j].x && b == k*p[len].y+p[j].y)break;
            }
           }
          if(j == len+1)printf("No\n");
          else printf("Yes\n");
        //}
    }
    return 0;
}