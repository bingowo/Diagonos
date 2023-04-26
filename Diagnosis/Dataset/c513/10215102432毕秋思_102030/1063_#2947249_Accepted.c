#include<stdio.h>

long long int effort_min(long long int x,long long int y)
{
    long long int L=x>=y?x:y;
    long long int S=x<y?x:y;
    if(L%S==0) return 4*L;
    else return 4*S+effort_min(L-S,S);
}

int main()
{
    long long int x,y;
    scanf("%lld%lld",&x,&y);
    printf("%lld",effort_min(x,y));
    return 0;
}
