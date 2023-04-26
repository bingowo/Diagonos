#include<stdio.h>
unsigned long long C(m,n)
{
    unsigned long long t=1;
    for(int i=1;i<=n;i++)
    {
        t=t*(m-i+1)/i;
    }
    return t;
}
int main()
{
    int number;
    scanf("%d",&number);
    for(int i=0;i<number;i++)
    {
        int m,n;
        scanf("%d%d",&m,&n);
        printf("case #%d:\n",i);
        printf("llu\n",C(m,n));
    }
    return 0;
}