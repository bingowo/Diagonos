#include <stdlib.h>
#include <stdio.h>
//思路与字符组合相似

typedef unsigned long long int LLU;

LLU f(int*w,int n,int target)
{
    if(target == 0 && n >= 0)
        return 1;
    else if(target != 0 && n == 0)
        return 0;
    int x[] = {-1,0,1},temp;
    for(int i = 0;i < 3;i++)
    {
        temp = f(w + 1,n - 1,target + w[0] * x[i]);
        if(temp == 1)
            return 1;
    }
    return 0;
}

int main()
{
    int n,i;
    scanf("%d",&n);
    int weight[n],sum = 0;
    for(i = 0;i < n;i++)
    {
        scanf("%d",&weight[i]);
        sum += weight[i];
    }
    for(i = 0;i < sum;i++)
    {
        printf("%d",f(weight,n,i + 1));
    }
    putchar('\n');
    return 0;
}
