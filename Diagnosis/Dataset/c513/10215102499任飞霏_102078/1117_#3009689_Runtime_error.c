#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    long long x,y,d;
}che;

long long Che(long long x0,long long y0,long long x,long long y)
{
    long long int ansx=0,ansy=0;
    ansx=llabs(x0-x);
    ansy=llabs(y0-y);
    if(ansx>=ansy)return ansx;
    else
        return ansy;
}

int cmp(const void* a,const void* b)
{
    che m=*((che*)a);
    che n=*((che*)b);
    if(m.d!=n.d){
        if(m.d>n.d)return -1;
        else
            return 1;
    }
    else{
        if(m.x!=n.x){
            if(m.x>n.x)return -1;
            else
                return 1;
        }
        else{
            if(m.y>n.y)return -1;
            else
                return 1;
        }
    }
}

int main()
{
    che a,s[10000];
    scanf("%lld%lld",&a.x,&a.y);
    int n;
    scanf("%d",&n);
    for(int t=0;t<n;t++){
        scanf("%lld%lld",&s[t].x,&s[t].y);
        s[t].d=Che(a.x,a.y,s[t].x,s[t].y);

    }
    qsort(s,n,sizeof(che),cmp);
    printf("%lld\n%lld %lld",s[n-1].d,s[n-1].x,s[n-1].y);
    return 0;
}
