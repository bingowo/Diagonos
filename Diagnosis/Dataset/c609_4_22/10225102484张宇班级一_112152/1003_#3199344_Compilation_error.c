#include<stdio.h>
void trans(long long int num)
{   if(num>0)
    {trans(num/2333);
    printf("%d ",num%2333);}
    elss if(num==0)
        printf("0");
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {   long long int num;
        scanf("%ld",&num);
        trans(num);
        printf("\n");
    }
    return 0;
}
