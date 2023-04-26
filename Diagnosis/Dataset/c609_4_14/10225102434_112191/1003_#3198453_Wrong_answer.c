#include<stdio.h>
void Turn(int x)
{
    int i,j;
    int y = 2333;
    int s[10000];
    for(i = 0;x>0;i++)
    {
       s[i] =x%y;
        x = x/y;
    }
    for(j = i-1;j>=0;j--)
        printf("%d ",s[j]);
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