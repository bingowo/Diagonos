#include<stdio.h>
int N =0;
void tian(int x,int y)
{
    if((x>0)&&(y>0))
    {
        int mini;
        if(x>y)
        {
            N=N+4*y;
            x=x-y;
            tian(x,y);
        }
        else
        {
            N=N+4*x;
            y=y-x;
            tian(x,y);
        }
        
        
    }
    else
        return 0;
}
int main()
{
    int x,y;
    scanf("%d%d",&x,&y);
    tian(x,y);
    printf("%d",N);
}