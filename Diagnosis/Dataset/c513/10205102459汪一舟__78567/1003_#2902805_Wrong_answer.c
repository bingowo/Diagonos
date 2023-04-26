#include<stdlib.h>
#include<stdio.h>
//using namespace std;
typedef long long LL;

//LL num[maxn];
const int maxn = 10005;
int getOneCount(LL a);
int cmp(const void* _a, const void* _b);

int main()
{
    LL num[maxn];
    int T,n;
    scanf("%d",&T);
    for(int kase=0; kase<T; kase++)
    {
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            scanf("%lld",&num[i]);
        }
        qsort(num,n,sizeof(num[0]),cmp);
        printf("case #%d:\n",kase);
        for(int i=0; i<n-1; ++i)
            printf("%lld ",num[i]);
        printf("%lld\n",num[n-1]);
    }
    return 0;
}

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

int cmp(const void* _a, const void* _b)
{
    LL* a = (LL*)_a;    //强制类型转换
    LL* b = (LL*)_b;
    int num_a=getOneCount(*a),num_b=getOneCount(*b);
    printf("a: %lld %d\n b:%lld %d\n",*a,num_a,*b,num_b);
    return(num_a==num_b)?((*a)>(*b)):(num_a<num_b);//if(==)return a<b else ..
}


