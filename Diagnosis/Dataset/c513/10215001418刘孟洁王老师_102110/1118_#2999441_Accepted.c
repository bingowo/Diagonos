#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int A[207][207];
int main()
{
    int w,h,d,i,j;
    char f[2];
    scanf("%d%d%d%s",&w,&h,&d,f);
    for(i = 0; i < h; i++)
        for(j = 0; j < w; j++)scanf("%d",&A[i][j]);
    d %= 360;
    if(d == 0)
        {
            printf("%d %d\n",w,h);
            for(i = 0; i < h; i++)
                for(j = 0; j < w; j++)printf("%d%c",A[i][j],j == w-1?'\n':' ');
        }
    else if(f[0] == 'L')
    {
        if(d == 90)
        {
            printf("%d %d\n",h,w);
            for(j = w-1; j >= 0; j--)
               for(i = 0; i < h; i++)printf("%d%c",A[i][j],i == h-1?'\n':' ');
        }
        else if(d == 180)
        {
            printf("%d %d\n",w,h);
            for(i = h-1; i >= 0; i--)
                for(j = w-1; j >= 0; j--)printf("%d%c",A[i][j],j == 0?'\n':' ');
        }
        else if(d == 270)
        {
            printf("%d %d\n",h,w);
            for(j = 0; j < w; j++)
                for(i = h-1; i >= 0; i--)printf("%d%c",A[i][j],i == 0?'\n':' ');
        }
    }
    else if(f[0] == 'R')
    {
        if(d == 90)
        {
            printf("%d %d\n",h,w);
            for(j = 0; j < w; j++)
                for(i = h-1; i >= 0; i--)printf("%d%c",A[i][j],i == 0?'\n':' ');
        }
        else if(d == 180)
        {
            printf("%d %d\n",w,h);
            for(i = h-1; i >= 0; i--)
                for(j = w-1; j >= 0; j--)printf("%d%c",A[i][j],j == 0?'\n':' ');
        }
        else if(d == 270)
        {
            printf("%d %d\n",h,w);
            for(j = w-1; j >= 0; j--)
               for(i = 0; i < h; i++)printf("%d%c",A[i][j],i == h-1?'\n':' ');
        }
    }
    return 0;
}
