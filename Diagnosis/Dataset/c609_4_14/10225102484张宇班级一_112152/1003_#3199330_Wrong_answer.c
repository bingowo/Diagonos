#include<stdio.h>
void trans(int num)
{   if(num>0)
    {trans(num/2333);
    printf("%d ",num%2333);}
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {   int num;
        scanf("%d",&num);
        trans(num);
    }
    return 0;
}