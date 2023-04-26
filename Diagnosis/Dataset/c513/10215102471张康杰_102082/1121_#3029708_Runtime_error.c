#include <stdlib.h>
#include <stdio.h>

int target[1001] = {0};
void comb(int*a,int t,int n,int depth)
{
    if(depth < n)
    {
        int temp1 = 0,temp2 = 0;
        temp1 = t + a[0];
        target[temp1] = 1;
        temp2 = t - a[0];
        target[abs(temp2)] = 1;
        comb(a + 1,t,n,depth + 1);
        comb(a + 1,temp1,n,depth + 1);
        comb(a + 1,temp2,n,depth + 1);
    }
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
    comb(weight,0,n,0);
    for(i = 1;i <= sum;i++)
    {
        printf("%d",target[i]);
    }
    putchar('\n');
    return 0;
}