#include<stdio.h>
//using namespace std;
int main(void)
{
    int t,cnt=0;
    scanf("%d",&t);
    while(cnt<t)
    {
        int n,cnt1=0;
        scanf("%d",&n);
        while(n/5)
        {
            cnt1+=n/5;
            n/=5;
        }
        printf("case #%d:\n%d\n",cnt++,cnt1);
    }
    return 0;
}