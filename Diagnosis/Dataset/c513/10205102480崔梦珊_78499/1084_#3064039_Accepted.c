#include<stdio.h>
#include<math.h>
typedef unsigned long long ll;
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        printf("case #%d:\n",i);
        ll a;
        scanf("%llu",&a);
        ll ans=pow(2,a);
        printf("%llu\n",ans);
    }
}

