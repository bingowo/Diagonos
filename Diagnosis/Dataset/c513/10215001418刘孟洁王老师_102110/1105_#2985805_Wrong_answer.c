#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int *s)
{
    int i,j,k,x = 256,sum[8];
    memset(sum,0,sizeof(sum));
    for(j = 0; j < 8; j++)
       {
           for(i = 0; i < 8; i++)sum[j] = sum[j]*2 + s[i];
           s[8] = s[0];
           for(k = 0; k < 8; k++)s[k] = s[k+1];
           if(sum[j] < x)x = sum[j];
           //printf("%d ",sum[j]);
       }
       //printf("\n");
    return x;
}

int main()
{
    int r,c,i,j;
    int A1[101][101],A2[101][101],s[9];
    scanf("%d%d",&r,&c);
    for(i = 0; i < 101; i++){memset(A1[i],0,sizeof(A1[i]));memset(A2[i],0,sizeof(A2[i]));}
    for(i = 0; i < r; i++)
        for(j = 0; j < c; j++)scanf("%d",&A1[i][j]);
    for(i = 1; i < r-1; i++)
        for(j = 1; j < c-1; j++)
        {
            memset(s,0,sizeof(s));
            if(A1[i-1][j-1] < A1[i][j])s[0] = 0;else s[0] = 1;
            if(A1[i-1][j] < A1[i][j])  s[1] = 0;else s[1] = 1;
            if(A1[i-1][j+1] < A1[i][j])s[2] = 0;else s[2] = 1;
            if(A1[i][j+1] < A1[i][j])  s[3] = 0;else s[3] = 1;
            if(A1[i+1][j+1] < A1[i][j])s[4] = 0;else s[4] = 1;
            if(A1[i+1][j] < A1[i][j])  s[5] = 0;else s[5] = 1;
            if(A1[i+1][j-1] < A1[i][j])s[6] = 0;else s[6] = 1;
            if(A1[i][j-1] < A1[i][j])  s[7] = 0;else s[7] = 1;
            A2[i][j] = min(s);
        }
    for(i = 1; i < r-1; i++)
    for(j = 1; j < c-1; j++)printf("%d%c",A2[i][j],j == c-2?'\n':' ');
    return 0;
}