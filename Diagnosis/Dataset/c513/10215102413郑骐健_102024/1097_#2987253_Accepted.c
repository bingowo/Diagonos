#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define r1 200
#define c1 200


int main()
{
    char m[300];
    while(scanf("%s",m)!=EOF)
    {
    char s[r1][c1];
    for(int i =0;i<r1;i++)
    {
        for(int r =0;r<c1;r++)s[i][r] = ' ';
    }
    int row =100;
    int col = 0;
    s[row][col] = m[col];
    for( col =1;col<strlen(m);col++)
    {
        if(m[col]>m[col-1])
        {
            row++;
        }
        else if(m[col]<m[col-1])
        {
            row-=1;
        }
        s[row][col] = m[col];

    }
    for(int i=0;i<r1;i++)
    {
        for(int k=c1-1;k>=0;k--)
        {
            if(s[i][k]!=' ')
            {
                s[i][k+1] = 0;
                break;
            }
            else if(k==0)s[i][k] = 0;
        }
    }
    for(int i=r1-1;i>=0;i--)
    {
        printf("%s",s[i]);
        if(strlen(s[i])!=0)printf("\n");
    }
    }

}

