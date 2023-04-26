#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int yes[10000];
int data[100];
void re(int t, int sum)
{
    if(t == -1)
    {
        if(sum > 0)
            yes[sum] = 1;
        return;
    }

    re(t - 1 , sum + data[t]);
    re(t - 1 , sum - data[t]);
    re(t - 1 , sum);
}

int main()
{
    int t;
    scanf("%d",&t);
    int sum = 0;
    memset(yes,0,sizeof(yes));
    for(int i = 0; i < t; i++)
    {
        int temp;
        scanf("%d",&temp);
        data[i] = temp;
        sum += temp;
    }
    re(t,0);

    for(int i = 1; i <= sum; i++)
        if(yes[i])
            printf("1");
        else
           printf("0");
}
