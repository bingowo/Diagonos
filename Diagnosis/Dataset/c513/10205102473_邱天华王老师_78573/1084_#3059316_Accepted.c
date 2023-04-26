#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
    int t;
    scanf("%d",&t);
    for(int i = 0; i < t; i++)
    {
        int n;
        scanf("%d",&n);
        long long cnt;
        cnt=pow(2,n);
        printf("case #%d: \n",i);
        printf("%d\n",cnt);
    }

    return 0;
}



