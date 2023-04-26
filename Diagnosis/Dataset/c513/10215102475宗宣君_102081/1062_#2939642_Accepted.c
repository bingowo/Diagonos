#include <stdio.h>
long long int A[50] = {0,1,2,4,8,15};
long long int answer(int a)
{
    if(a<=5) return A[a];
    else
    return 2*answer(a-1)-answer(a-5);
}
int main()
{
    int T,i;
    scanf("%d",&T);
    for(i =0;i<T;i++)
    {
        int n;long long int res;
        scanf("%d",&n);
        res = answer(n);
        printf("case #%d:\n%lld\n",i,res);
    }
    return 0;
}
