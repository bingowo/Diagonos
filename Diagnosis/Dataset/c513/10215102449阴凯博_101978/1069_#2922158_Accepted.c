#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int cnt;
    int result;
} NUM;

int reverse(int n)
{
    int i=10,m=0;
    while (n)
    {
        m=m*10+n%10;
        n=n/10;
    }
    return m;
}

NUM huiwen(int n)
{
    NUM rr;
    rr.cnt=0;
    while (n!=reverse(n))
    {
        n=n+reverse(n);
        rr.cnt++;
    }
    rr.result=n;
    return rr;

}

int main()
{
    int n,i,m;
    scanf("%d",&n);
    NUM r1=huiwen(n);
    printf("%d %d\n",r1.cnt,r1.result);
    return 0;
}
