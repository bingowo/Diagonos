#include <stdio.h>
#include <stdlib.h>

int f(int n,int m,int max,int m1)
{
    if(n==0){
        if(max>=m) return 1;
        else return 0;
    }
    else{
        m1++;
        int max1=max;
        if(m1>max) max1=m1;
        return f(n-1,m,max1,m1)+f(n-1,m,max,0);
    }
}

int main()
{
    int n=0,m=0;
    while(1){
        scanf("%d %d",&n,&m);
        int max=0,ans=0,m1=0;
        if (n==-1) break;

        else{
            ans=f(n,m,max,m1);
            printf("%d\n",ans);
        }
    }
    return 0;
}
