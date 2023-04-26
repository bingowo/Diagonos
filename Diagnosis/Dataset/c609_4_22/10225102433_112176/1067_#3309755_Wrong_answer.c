#include <stdio.h>
#include <math.h>
#define N 20

int k;
int a,n,m,x;
int sum;
int all;

void find(int cnt1,int cnt2,int precnt1,int precnt2,int t)
{
    if(t < n)
    {
        sum += (cnt1*a);
        all += cnt2;
        find(precnt1,precnt2,cnt1+precnt1,cnt2+precnt2,t+1);
    }
    else
    {
        return;
    }
}


int main()
{
    scanf("%d %d %d %d",&a,&n,&m,&x);
    if(x <= 2) printf("%d",a);
    else
    {
        sum = a;
        find(1,0,0,1,3);
    }
    int res = (m-sum)/all;
    int pre = a;
    int up = res;
    int ans = a;
    for(int i = 2;i < x;i++)
    {
        ans += pre;
        int tool1 = pre;
        int tool2 = up;
        pre = up;
        up = tool1+tool2;
    }
    printf("%d",ans);
    return 0;
}