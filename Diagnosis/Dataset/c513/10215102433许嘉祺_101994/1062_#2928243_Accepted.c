#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
    int n;
    scanf("%d",&n);
    long long step[50];
    step[1]=1;
    step[2]=2;
    step[3]=4;
    step[4]=8;
    for (int i=5;i<=50;i++) step[i]=step[i-1]+step[i-2]+step[i-3]+step[i-4];
    for (int i=0;i<n;i++){
        int grade;
        scanf("%d",&grade);

        printf("case #%d:\n",i);
        printf("%lld\n",step[grade]);
    }
    return 0;
}