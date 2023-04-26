#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

int main()
{
    int T;scanf("%d",&T);
    for(int step=0;step<T;step++){
        printf("case #%d:\n",step);
        char light[5][5];
        for(int i=1;i<4;i++)
            for(int j=1;j<4;j++)
                light[i][j]=1;
        for(int i=1;i<4;i++)
            for(int j=1;j<4;j++){
                int res=0;
                scanf("%d",&res);
                light[i][j]+=res;
                light[i+1][j]+=res;
                light[i-1][j]+=res;
                light[i][j-1]+=res;
                light[i][j+1]+=res;
                }
        for(int i=1;i<4;i++)
            for(int j=1;j<4;j++)
                light[i][j]%=2;
        for(int i=1;i<4;i++){
            for(int j=1;j<4;j++)
                printf("%d ",light[i][j]);
            printf("\n");
        }
    }
    return 0;
}
