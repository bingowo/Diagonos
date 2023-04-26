#include <stdio.h>
#include <math.h>
int main()
{
    int a,n,m,x,res,p;
    scanf("%d %d %d %d",&a,&n,&m,&x);
    if(x==1) res = a;
    else if(x==2) res = a;
    else if(x==3) res = a;
    else
    {
        p = (m-(n-3)*a)/(int)pow(2,n-5);
        res = pow(2,x-4)*p+(x-2)*a;
    }
    printf("%d",res);
    return 0;

}
