#include <stdlib.h>
#include <stdio.h>

int target[1001] = {0};
void comb(int*a,int t)
{
    if(a[0] > 0)
    {
        target[t] = 0;
        int temp1 = 0,temp2 = 0;
        temp1 = t + a[0];
        target[temp1] = 1;
        temp2 = t - a[0];
        target[abs(temp2)] = 1;
        comb(a + 1,t);
        comb(a + 1,temp1);
        comb(a + 1,temp2);
    }
}

int main()
{
    int n,i;
    scanf("%d",&n);
    int weight[n + 1],sum = 0;
    for(i = 0;i < n;i++)
    {
        scanf("%d",&weight[i]);
        sum += weight[i];
    }
    weight[n] = -1;
    comb(weight,0);
    for(i = 1;i <= sum;i++)
    {
        printf("%d",target[i]);
    }
    putchar('\n');
    return 0;
}