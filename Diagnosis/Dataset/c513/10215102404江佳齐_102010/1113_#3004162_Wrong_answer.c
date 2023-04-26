#include <stdio.h>
#include <stdlib.h>
long long int f(int k,int n)
{
    int i,j;
    long long int s[15][110];
    if(n==1) return 0;
    if(n==2) return 1;
    s[k][1]=0;s[k][2]=1;
    for(i=3;i<=110;i++) s[k][i]=0;
    switch(k)
    {
        case 3:
            s[3][3]=1;
            if(n==3) return 1;
            break;
        case 4:
            s[4][3]=1;s[4][4]=2;
            if(n==3) return 1;
            if(n==4) return 2;
            break;
        case 5:
            s[5][3]=1;s[5][4]=2;s[5][5]=4;
            if(n==3) return 1;
            if(n==4) return 2;
            if(n==5) return 4;
            break;
        case 6:
            s[6][3]=1;s[6][4]=2;s[6][5]=4;s[6][6]=8;
            if(n==3) return 1;
            if(n==4) return 2;
            if(n==5) return 4;
            if(n==6) return 8;
            break;
        case 7:
            s[7][3]=1;s[7][4]=2;s[7][5]=4;
            s[7][6]=8;s[7][7]=16;
            if(n==3) return 1;
            if(n==4) return 2;
            if(n==5) return 4;
            if(n==6) return 8;
            if(n==7) return 16;
            break;
        case 8:
            s[8][3]=1;s[8][4]=2;s[8][5]=4;
            s[8][6]=8;s[8][7]=16;s[8][8]=32;
            if(n==3) return 1;
            if(n==4) return 2;
            if(n==5) return 4;
            if(n==6) return 8;
            if(n==7) return 16;
            if(n==8) return 32;
            break;
        case 9:
            s[9][3]=1;s[9][4]=2;s[9][5]=4;
            s[9][6]=8;s[9][7]=16;s[9][8]=32;s[9][9]=64;
            if(n==3) return 1;
            if(n==4) return 2;
            if(n==5) return 4;
            if(n==6) return 8;
            if(n==7) return 16;
            if(n==8) return 32;
            if(n==9) return 64;
            break;
        case 10:
            s[10][3]=1;s[10][4]=2;s[10][5]=4;s[10][6]=8;
            s[10][7]=16;s[10][8]=32;s[10][9]=64;s[10][10]=128;
            if(n==3) return 1;
            if(n==4) return 2;
            if(n==5) return 4;
            if(n==6) return 8;
            if(n==7) return 16;
            if(n==8) return 32;
            if(n==9) return 64;
            if(n==10) return 128;
            break;
    }
    for(i=k+1;i<=n;i++)
    {
        for(j=1;j<=k;j++) s[k][i]+=s[k][i-j];
    }
    return s[k][n];
}
int main()
{
    int k,n;
    scanf("%d %d",&k,&n);
    long long int sum;
    sum=f(k,n);
    printf("%lld",sum);
    return 0;
}
