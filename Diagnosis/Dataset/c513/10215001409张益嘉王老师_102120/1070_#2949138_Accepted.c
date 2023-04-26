#include <stdio.h>
#include <stdlib.h>

int cun[21];

int way(int n)
{
    if(n==0) {cun[0]=0;return 0;}
    else if(n==1) {cun[1]=2;return 2;}
    else if(n==2) {cun[2]=4;return 4;}
    else if(n==3) {cun[3]=7;return 7;}
    else
    {
        if(cun[n-1]==-1) cun[n-1]=way(n-1);
        if(cun[n-2]==-1) cun[n-2]=way(n-2);
        if(cun[n-3]==-1) cun[n-3]=way(n-3);
        cun[n]=2*cun[n-1]-cun[n-2]+cun[n-3];
        return cun[n];
    }


}

int main()
{

    while(1)
    {
        int n,re;
        scanf("%d",&n);
        if(n==-1) break;
        memset(cun,-1,sizeof(int)*21);
        re=way(n);
        printf("%d\n",re);
    }
    return 0;


}
