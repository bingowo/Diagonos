#include<stdio.h>
int main()
{
    int number;
    scanf("%d",&number);
    for(int i=0;i<number;i++)
    {
        int n;
        scanf("%d",&n);
        unsigned long long a=1;
        for(int j=0;j<n;j++)
        {
            a=a*2;
        }
        printf("case #%d:\n",i);
        printf("%llu\n",a);
    }
    return 0;
}