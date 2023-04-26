#include<stdlib.h>
#include<stdio.h>
#include<algorithm.h>
using namespace std;
typedef long long LL;

const int maxn = 10005;
LL num[maxn];

int getOneCount(LL a)
{
    int cnt=0;
    while(a!=0)
    {
        cnt++;
        a&=(a-1);//用来去掉a二进制最左边的1
    }
    return cnt;
}

bool cmp(LL a,LL b)
{
    int num_a=getOneCount(a),num_b=getOneCount(b);
    return(num_a==num_b)?(a<b):(num_a>num_b);//if(==)return a<b else ..
}

int main()
{
    int T,n;
    scanf("%d",&T);
    for(int kase=0;kase<T;kase++)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&num[i]);
        }
        sort(num,num+n,cmp);
        printf("case #%d:\n",kase);
        for(int i=0;i<n-1;++i)
            printf("%lld ",num[i]);
        printf("%lld\n",num[n-1]);
    }
    return 0;
}
