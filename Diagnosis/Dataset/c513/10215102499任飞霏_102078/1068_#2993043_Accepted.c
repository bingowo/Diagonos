#include <stdio.h>
#include <stdlib.h>

/*
当m>n时候 0，n全是1也无法凑出来满足的字符串
当m==n时候 1，有且只有一个满足的字符
当m<n时候 我们假设满足条件的字符串为f(m,n)
当n变成n+1的时候
①
不难发现，在f(m,n)的基础上无论加1或者加0，得到的新的字符串都满足题目要求的“存在连续m个数字都是1”这个条件

②
但是我们发现当 长度为n的字符串的末尾m-1个数字都恰好为1（且倒是第m个数字是0的时候）的时候，我们再加上一个1，就会导致新生成的n+1长度的字符串的末尾恰好有m个字符串
满足该字符串（末尾m-1个数字是1，倒数第m个数字是0）的情况有
2 n − m − 1 种 2^{n-m-1}种
2 
n−m−1
 种

注意：倘若在前n-m-1中的数字里面存在连续m个字符串，那么这种情况已经被情况①包含了，所以我们需要减去对应的已经被情况①包含的情况。
f ( m , n − m − 1 ) f(m,n-m-1)
f(m,n−m−1)

所以我们可以得到递推关系
f ( m , n + 1 ) = 2 f ( m , n ) + 2 n − m − 1 − f ( m , n − m − 1 ) f(m,n+1) = 2f(m,n) +2^{n-m-1} - f(m,n-m-1)
f(m,n+1)=2f(m,n)+2 
n−m−1
 −f(m,n−m−1)
*/

long long re(int n,int m)
{
    long long ans = 0;
    if(n<m){
        ans=0;
    }
    else if(n==m){
        ans=1;
    }
    else{
        ans=2*re(n-1,m)+(1<<(n-m-1))-re(n-m-1,m);
    }
    return ans;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    while(!(n==-1&&m==-1)){
        long long ans = 0;
        ans = re(n,m);
        printf("%lld\n",ans);
        scanf("%d%d",&n,&m);
    }
    return 0;
}
