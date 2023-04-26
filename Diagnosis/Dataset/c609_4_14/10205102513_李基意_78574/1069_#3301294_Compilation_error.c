#include <stdio.h>
#include <math.h>

int main()
{
    int m, n;
    long long num[32][32];
    for(int i=1;i<32;++i){num[i][i]=1;}
    for(int i=2;i<32;++i)
        for(int j=1;j<i;++j){
            num[i][j]=2*num[i-1][j]+int(pow(2.0,double(i-j-1)));
            if(i>2*j) num[i][j]-=num[i-j-1][j];}
    scanf("%d%d",&n,&m);
    while(m+1&&n+1){
        printf("%lld",num[m][n]);
        scanf("%d%d",&n,&m);
    }
    return 0;
}