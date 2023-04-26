#include <stdio.h>
#include <stdlib.h>

int main()
{
    int res[21][4];
    res [3][0] = 2;// 11,10,00,01;
    res [3][1] = 2;// 11,10,00,01;
    res [3][2] = 2;// 11,10,00,01;
    res [3][3] = 1;// 11,10,00,01;
    for(int i =4;i<21;i++)
    {
        res[i][0] = res[i-1][0]+res[i-1][3];
        res[i][1] = res[i-1][0]+res[i-1][3];
        res[i][2] = res[i-1][1]+res[i-1][2];
        res[i][3] = res[i-1][2];
    }
    int n;
    while(scanf("%d",&n),n!=-1)
    {
        if(n==1)printf("2\n");
        else if(n==2)printf("4\n");
        else{printf("%d\n",res[n][0]+res[n][1]+res[n][2]+res[n][3]);
        
        }
    }
    return 0;
}
