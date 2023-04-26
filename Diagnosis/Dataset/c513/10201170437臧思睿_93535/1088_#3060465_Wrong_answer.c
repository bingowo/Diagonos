#include <stdio.h>
#include <stdlib.h>
//const int M=10007;
typedef long long int ll;

int main()
{
    int i,j,t=0,T;
    ll table[45][45];//table to store combination
    for(i=0;i<=40;i++)
    {
        table[i][0]=1;
        table[i][1]=(ll)i;
    }
    table[2][2]=1;table[3][2]=3;
    for(i=4;i<=40;i++)
    {
        for(j=2;j<=i/2+1;j++)
        {
            if(2*j<i-1)
            {
                table[i][j]=table[i-1][j]+table[i-1][j-1];
            }
            else{table[i][j]=table[i-1][i-1-j]+table[i-1][j-1];}
            //table[i][j]%=M;
        }
    }
    for(i=0;i<=40;i++)
    {
        for(j=i;j>i/2;j++)
        {
            table[i][j]=table[i][i-j];
        }
    }
    scanf("%d",&T);
    while(t++<T)
    {
        printf("case #%d:\n",t-1);
        scanf("%d %d",&i,&j);
        printf("%lld\n",table[i][j]);
    }
    return 0;
}
