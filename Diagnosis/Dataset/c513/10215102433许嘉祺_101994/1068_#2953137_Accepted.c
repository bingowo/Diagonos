#include <stdio.h>
#include <stdlib.h>
#include<string.h>


int main()
{
    int n,m;
    int a[32][32];
    memset(a,0,sizeof(a));

    for (int i=1;i<=31;i++) a[i][i]=1;
    for (int i=1;i<=31;i++){
        for (int j=i+1;j<=31;j++){
            a[j][i]=a[j-1][i];
            if (i!=1)
            for (int k=j-2;k>=i&&k>=j-i;k--)
                a[j][i]+=a[k][i];
            int d=1;
            for (int k=1;k<=j-i;k++)
                d=d*2;
            a[j][i]+=d;
        }

    }
    
    scanf("%d%d",&n,&m);
    int ans;
    while (n!=-1){

        printf("%d\n",a[n][m]);
        scanf("%d%d",&n,&m);
    }


    return 0;
}