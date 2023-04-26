#include <stdio.h>
#include <math.h>
const int M=10007;
typedef long long int ll;

int poww(int p,int q)
{
    int i;
    ll r=(ll)p;
    if(q==0){return 1;}
    for(i=1;i<q;i++)
    {
        r*=p;
        r%=M;
    }
    //printf("%d\n",r);
    return r;
}

int main()
{
    int i,j,t=0,T,table[1005][505];//table to store combination
    for(i=0;i<=1000;i++)
    {
        table[i][0]=1;
        table[i][1]=i;
    }
    table[2][2]=1;table[3][2]=3;
    for(i=4;i<=1000;i++)
    {
        for(j=2;j<=i/2+1;j++)
        {
            if(2*j<i-1)
            {
                table[i][j]=table[i-1][j]+table[i-1][j-1];
            }
            else{table[i][j]=table[i-1][i-1-j]+table[i-1][j-1];}
            table[i][j]%=M;
        }
    }
    //scanf("%d %d",&i,&j);
    //printf("%d",table[i][j]);
    scanf("%d",&T);
    while(t++<T)
    {
        int a,b,k,n,m;
        ll r;
        printf("case #%d:\n",t-1);
        scanf("%d %d %d %d %d",&a,&b,&k,&n,&m);
        //printf("%d",table[k][n]);
        //r=((ll)poww(a,n)*(ll)poww(b,m))%M;
        //printf("%d\n",r);
        if(n<=m)
        {
            r=(((ll)table[k][n]%M)*((ll)poww(a,n)*(ll)poww(b,m))%M)%M;
        }
        else{r=(((ll)table[k][m]%M)*((ll)poww(a,n)*(ll)poww(b,m))%M)%M;}
        printf("%d\n",r);
    }
    return 0;
}
