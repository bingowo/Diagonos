#include <stdio.h>

int main()
{
    int i,d,n;
    int k[1000],s[1000];
    double t[1000];
    double ans;
    scanf("%d",&d);
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d%d",&k[i],&s[i]);
        t[i]=((double)d-(double)k[i])/(double)s[i];
    }
    for(i=1;i<n;i++)
        if(t[i]<t[i-1])
            t[i]=t[i-1];
    ans=(double)d/t[n-1];
    printf("%.6f\n",ans);
    return 0;
}
