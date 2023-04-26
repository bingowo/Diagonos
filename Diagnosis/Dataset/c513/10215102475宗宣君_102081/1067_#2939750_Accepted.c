#include <stdio.h>
long long int A[75] = {0,1,1};
long long int answer(int a)
{
    int i;
    for(i = 3;i<=a;i++)
        A[i] = A[i-1] + A[i-2] + A[i-3];
    return A[a];
}
int main()
{
    int T,i;
    scanf("%d",&T);
    for(i =0;i<T;i++)
    {
        int n;
        scanf("%d",&n);
        long long int res;
        res = answer(n);
        printf("case #%d:\n%lld\n",i,res);
    }

}
