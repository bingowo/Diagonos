#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main()
{
    int T;
    scanf("%d",&T);
    long long int Tri[37] = {0,1,1};
    for(int i = 3 ; i < 37 ; i++)
        Tri[i] = Tri[i-1] + Tri[i-2] +Tri[i-3];
    for(int i = 0 ; i < T; i++)
    {
        int n;
        scanf("%d",&n);
        printf("case #%d:\n%lld\n",i,Tri[n]);
    }
}
