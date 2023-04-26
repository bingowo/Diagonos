#include<stdio.h>
void ming(int x,int y)
{
    if(x>0)
    {
        ming(x/y,y);
        printf("%d ",x%y);
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int x,y=2333;
        scanf("%d",&x);
        if(x<0)
        {
            printf("-");
            x=x*-1;
        }
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