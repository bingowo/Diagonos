#include <stdio.h>
long long int answer(int a)
{
    if(a==0) return 0;
    else if(a==1||a==2) return 1;
    else if(a==3) return 2;
    else return 2*answer(a-1)-answer(a-4);
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
