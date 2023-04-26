#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>

#define N 1001
#define INF 1000009

typedef long long int lli;

int gcd(int a ,int b)
{
    if (a%b==0) return b;
    else return gcd(b,a%b);
}

int cmp(const void * a,const void * b)
{
    return *(int*)a-*(int*)b;
}

int main(void)
{
    int n,s;
    scanf("%d%d",&n,&s);
    int a[1001];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    qsort(a,n,sizeof(int),cmp);
    a[n]=INF;
    int ans_fenzi=0,ans_fenmu=0,ans_int=0;
    for(int i=1;i<=n;i++)
    {
        ans_fenzi=0;ans_fenmu=0;ans_int=0;
        int c = (a[i]-a[i-1])*i;
        if(c>=s)
        {
            ans_int = s/i+a[i-1];
            ans_fenzi=s%i;
            ans_fenmu=i;
            if (ans_fenzi!=0)
            {
                int g = gcd(ans_fenmu,ans_fenzi);
                ans_fenzi/=g;ans_fenmu/=g;
            }

            break;
        }
        else
        {
            s-=c;
        }
    }
    if (ans_fenzi ==0) printf("%d",ans_int);
    else printf("%d+%d/%d",ans_int,ans_fenzi,ans_fenmu);
    return 0;

}
