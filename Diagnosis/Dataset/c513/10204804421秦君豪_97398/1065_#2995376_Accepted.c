#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>


#define INF 1000009

typedef long long int lli;
int upA[21]={0,1,0};
int upB[21]={0,0,1};

int calupA(int stop)
{
    if(stop==1) return 1;
    else if (stop==2) return 0;
    else
    {
        upA[stop] =calupA(stop-1)+calupA(stop-2);
        return upA[stop];
    }
}

int calupB(int stop)
{
    if (stop==1) return 0;
    else if(stop==2) return 1;
    else
    {
        upB[stop]=calupB(stop-1)+calupB(stop-2);
        return upB[stop];
    }
}

int calcoA(int x)
{
    if(x==1) return 1;
    else if(x==2) return 1;
    else return calcoA(x-1)+upA[x-2];
}

int calcoB(int x)
{
    if(x==1) return 0;
    else if(x==2) return 0;
    else
    {
        return calcoB(x-1)+upB[x-2];
    }
}



int main(void)
{
    int a,n,m,x;
    scanf("%d%d%d%d",&a,&n,&m,&x);
    calupA(n);
    calupB(n);
//////    for (int i=1;i<n;i++)
////    {
////        printf("%d %d\n",upA[i],upB[i]);
//    }
    int b= (m-(calcoA(n-1)*a))/(calcoB(n-1));
    if(x==1) printf("%d",a) ;

    else printf("%d",a*calcoA(x)+b*calcoB(x));
//    printf("\n%d %d",calcoA(4),calcoB(4));
    return 0;

}
