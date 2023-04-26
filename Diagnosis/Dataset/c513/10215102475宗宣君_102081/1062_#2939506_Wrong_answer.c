#include <stdio.h>
long long int answer(int a)
{
    if(a-4>0) return answer(a-4)*8;
    else if(a==1) return 1;
    else if(a==2) return 2;
    else if(a==3) return 3;
    else if(a==4) return 8;
}
int main()
{
    int T,i;
    scanf("%d",&T);
    for(i =0;i<T;i++)
    {
        int n;
        long long int res;
        scanf("%d",&n);
        res = answer(n);
        printf("case #%d:\n%lld\n",i,res);
    }
    return 0;
}
