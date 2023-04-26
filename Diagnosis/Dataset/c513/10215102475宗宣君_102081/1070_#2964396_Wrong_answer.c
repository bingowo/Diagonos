#include <stdio.h>
#include <math.h>
int none(int n)
{
    if(n==3) return 1;
    else if(n<3) return 0;
    else return 2*none(n-1)+pow(2,n-3)-none(n-3);
}
int main()
{
    while(1)
    {
        int n;
        scanf("%d",&n);
        if(n==-1) break;
        printf("%d\n",(int)pow(2,n)-none(n));
    }
    return 0;
}
