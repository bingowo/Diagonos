#include <stdio.h>
#include <stdlib.h>
int up[21]={0,1};
int na[21]={0};
int nx[21]={0,0,0,0,1};
int makeup(int n)
{
    if(n==1)return 1;
    if(n==2||n<=0)return 0;
    else{
        up[n] = makeup(n-1)+makeup(n-2);
        return up[n];
    }

}

int makea(int n)
{
    if(n==1||n==2)return 1;
    else if(n<=0)return 0;
    else{
        na[n]=makea(n-1)+up[n-2];
        return na[n];
    }
}

int makex(int n)
{
    if(n<3)return 0;
    if(n==3||n==4)return 1;
    else{
        nx[n] = makex(n-1)+makex(n-2);
        return nx[n];
    }

}

int main()
{
    int a,n,m,x;
    scanf("%d%d%d%d",&a,&n,&m,&x);
    int up = makeup(n-1);
    int numa = makea(n-1);
    makex(n-1);
    int numx = 0;
    if(x>=3)numx+=2;
    for(int i=5;i<n-1;i++){
        numx+=nx[i];
    }
    int vx = 0;
    if(numx == 0){
        vx = 1;
    }
    else{
        vx = (m-a*numa)/numx;
    }
    printf("%d\n",na[x]*a+nx[x]*vx);
    return 0;
}
