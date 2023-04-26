#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int cas,i,r,c;
    int A1[3][3],A2[3][3];
    scanf("%d",&cas);
    for(i = 0; i < cas; i++)
    {
        for(r = 0; r < 3; r++)
            for(c = 0; c < 3; c++)scanf("%d",&A2[r][c]);
        for(r = 0; r < 3; r++)
            for(c = 0; c < 3; c++)A1[r][c] = 1;
        for(r = 0; r < 3; r++)
               for(c = 0; c < 3; c++)
              {
                 if(A2[r][c]%2)
                 {
                   A1[r][c] = abs(A1[r][c]-1);
                   if(r >= 1)A1[r-1][c] = abs(A1[r-1][c]-1);
                   if(r <= 1)A1[r+1][c] = abs(A1[r+1][c]-1);
                   if(c >= 1)A1[r][c-1] = abs(A1[r][c-1]-1);
                   if(c <= 1)A1[r][c+1] = abs(A1[r][c+1]-1);
                  }
               }
        printf("case #%d:\n",i);
        for(r = 0; r < 3; r++)
            for(c = 0; c < 3; c++)printf("%d%c",(A1[r][c]),c == 2?'\n':' ');
    }
    return 0;
}