#include<stdio.h>
void Turn(long long int x)
{
    int i = 0,j;
    int y = 2333;
    long long int s[100000];
    if(x==0)
    {
        printf("0\n");
        return;
    }

    for(i = 0;x>0;i++)
    {
       s[i] =x%y;
        x = x/y;
    }
    for(j = i-1;j>=0;j--)
        printf("%lld ",s[j]);
    printf("\n");
}
int main()
{
    int n;
    scanf("%d",&n);
    long long int s[n];
    int i,j,k;
    for(i = 0;i<n;i++)
        scanf("%lld",&s[i]);
    for(i = 0;i<n;i++)
        Turn(s[i]);
    return 0;
}

