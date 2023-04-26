#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


//long long Tri( int n )
//{
//    if(n==0)    return 0;
//    if(n==1 || n==2)    return 1;
//    return Tri(n-1) + Tri(n-2) + Tri(n-3);
//}

long long int Tri[37] = {0,1,1};

void initial()
{
    int i;
    for(i = 3 ; i < 37 ; i++)
        Tri[i] = Tri[i-1] + Tri[i-2] +Tri[i-3];
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i = 0 ; i < T; i++)
    {
        int n;
        scanf("%d",&n);
        printf("case #%d:\n%lld\n",i,Tri[n]);
    }
}
