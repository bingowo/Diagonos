#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 205

int min(int a,int b){return a<b?a:b;}

void reverse(char* s)
{
    char temp;
    for(int i=0,j=strlen(s)-1;i<j;++i,--j){
        temp=s[i];s[i]=s[j];s[j]=temp;
    }
}

int main()
{
    int a[N][N],dp[N][N];
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j)a[i][j]=dp[N][N]=0;
    }
    int m,n;
    scanf("%d%d\n",&m,&n);
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j)scanf("%d",&a[i][j]);
    }
    char show[N*2]={0};int ps=0;
    dp[0][0]=a[0][0];
    //if(dp[1][0]<dp[0][1])show[ps++]='D';
    //else show[ps++]='R';
    for(int i=1;i<n;++i)dp[0][i]=a[0][i]+dp[0][i-1];
    for(int i=1;i<m;++i)dp[i][0]=a[i][0]+dp[i-1][0];
    for(int i=1;i<m;++i){
        for(int j=1;j<n;++j){
            dp[i][j]=a[i][j]+min(dp[i-1][j],dp[i][j-1]);
        }
    }

    int x=m-1,y=n-1;
    while(x!=0||y!=0){
        if(x==0){
            show[ps++]='R';
            y--;
        }
        else if(y==0){
            show[ps++]='D';
            x--;
        }
        else{
            if(dp[x-1][y]>dp[x][y-1]){
                show[ps++]='R';
                y--;
            }
            else{
                show[ps++]='D';
                x--;
            }
        }
    }
    reverse(show);

    printf("%d\n",dp[m-1][n-1]);
    printf("%s\n",show);
    return 0;
}
