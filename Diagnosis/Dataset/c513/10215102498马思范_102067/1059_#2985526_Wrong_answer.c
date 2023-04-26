#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
int cmp(const void *a,const void *b)
{
    return *(int*)a-*(int*)b;
}
int main()
{
    int n,s;
    scanf("%d%d",&n,&s);
    int a[1001];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    qsort(a,n,sizeof(a[0]),cmp);
    int ans,fz,fm;
    for(int h=1;h<=n;h++)
    {
        int c=(a[h]-a[h-1])*h;
        if(s<c)
        {
            ans=a[h-1]+s/h;
            fz=s%h;
            fm=h;
            break;
        }
        else
            s=s-c;
    }
    int g= gcd(fz,fm);
    fz=fz/g;
    fm=fm/g;
    if(ans==0&&fz>0)
    {
        printf("%d/%d",fz,fm);
    }
    else
    {
        printf("%d",ans);
        if(fz>0)
        {
            printf("+%d/%d",fz,fm);
        }
    }
    return 0;
}