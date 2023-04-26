#include <stdio.h>
int main()
{
    int cnt=0;
    int num=0;
    scanf("%d",&cnt);
    char s[61];
    int L[128];
    scanf("%s",s);
    for(int i=0;i<128;i++)
    {
        L[i]=-1;
    }
    int digit =0;
    int N=1,i;
    char *p = s;
    L[*p]=1;
    while(*++p)
    {
        if(L[*p]==-1){
            L[*p]=digit;
            digit=digit? digit+1:2;
            N++;
        }
    }
    if(N<2){N=2;}
    long long ans =0;
    p=s;
    while(*p)
    {
        ans=ans*N+L[*p++];
    }
    printf("%lld\n",ans);
    return 0;
 
}