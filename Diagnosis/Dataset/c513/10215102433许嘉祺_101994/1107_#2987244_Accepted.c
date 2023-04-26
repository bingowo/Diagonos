#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int t;
    scanf("%d",&t);
    int a[5][5];
    int state[4][4];
    memset(a,0,sizeof(a));
    for (int i=0;i<t;i++){
        for (int j=1;j<4;j++)
            for (int k=1;k<4;k++)
            scanf("%d",&a[j][k]);
            printf("case #%d:\n",i);
        for (int j=1;j<4;j++)
            for (int k=1;k<4;k++)
            state[j][k]=(1+a[j-1][k]+a[j][k]+a[j+1][k]+a[j][k+1]+a[j][k-1])%2;
        for (int j=1;j<4;j++){
            for (int k=1;k<3;k++)
                printf("%d ",state[j][k]);
            printf("%d\n",state[j][3]);
        }
    }
    return 0;
}
