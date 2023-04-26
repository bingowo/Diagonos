#include<stdio.h>
void ming(long long int x,long long int y)
{
    if(x>0)
    {
        ming(x/y,y);
        printf("%lld ",x%y);
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        long long int x,y=2333;
        
        scanf("%lld",&x);
        
        if(x==0)
        {
            printf("0");
        }
        else
        {
            ming(x,y);
        }
        printf("\n");
    }
    
}