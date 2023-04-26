#include<stdio.h>
int find(int n)
{
    int result=0;
    while(n%5==0)
    {
        result++;
        n=n/5;
    }
    return result;
}
int main()
{
    int number;
    scanf("%d",&number);
    for(int i=0;i<number;i++)
    {
        int n;
        scanf("%d",&n);
        int t=0;
        for(int j=n;j>0;j--)
        {
            t=t+find(j);
        }
        printf("case #%d:\n",i);
        printf("%d\n",t);
    }
    return 0;
}