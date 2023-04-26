#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,i,n;
    scanf("%d",&T);
    unsigned long long int record[51] = {1,1,2,4,8};
    for(i = 5;i < 50;i++)
    {
        record[i] = record[i - 1] + record[i - 2] + record[i - 3] + record[i - 4];
    }
    for(i = 0;i < T;i++)
    {
        scanf("%d",&n);
        printf("case #%d:\n%llu\n",i,record[i]);
    }
     
}