#include <stdio.h>

long long f(long long x,long long y)
{return (x > y) ? x : y;}

long long F(long long x,long long y)
{return ((long long)(x - y) > 0) ? (long long)(x - y) : (long long)(y - x);}

int main()
{
    long long x0,y0,Min,x,y;
    scanf("%lld%lld",&x0,&y0);
    int n,i,j,k;
    scanf("%d",&n);
    long long L[n][2];
    for (i = 0; i < n; i++){
        scanf ("%lld%lld",&L[i][0],&L[i][1]);
        long long dx = F(L[i][0],x0);
        long long dy = F(L[i][1],y0);

        if (i == 0){
            x = L[0][0];
            y = L[0][1];    
            Min = f(dx,dy);
        }

        long long dMin = f(dx,dy);

        if (dMin < Min){
            x = L[i][0];
            y = L[i][1];
            Min = dMin;
        }else if (dMin == Min){
            if (L[i][0] < x){
                x = L[i][0];
                y = L[i][1];
                Min = dMin;
            }else if (L[i][0] == x){
                if (L[i][1] < y){
                    x = L[i][0];
                    y = L[i][1];
                    Min = dMin;                    
                }
            }
        }        
    }
    printf("%lld\n%lld %lld\n",Min,x,y);
    return 0;
}