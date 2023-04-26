#include<stdio.h>
long long int N =0;
void tian(long long int x,long long int y)
{
    if((x>0)&&(y>0))
    {
        if(x>y)
        {
            if(x%y==0)
            {
                N = N+(x/y)*4*x;
                return 0;
            }
            else
            {
                N=N+4*y;
                x=x-y;
                tian(x,y); 
            }
            
        }
        else
        {
            if(y%x==0)
            {
                N = N+(y/x)*4*x;
                return 0;
            }
            else
            {
                N=N+4*x;
                y=y-x;
                tian(x,y); 
            }
            
        }
        
        
    }
    else
        return 0;
}
int main()
{
    long long int x,y;
    scanf("%lld%lld",&x,&y);
    tian(x,y);
    printf("%lld",N);
}