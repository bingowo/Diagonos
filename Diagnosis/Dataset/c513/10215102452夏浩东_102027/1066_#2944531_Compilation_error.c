#include <stdio.h>
#include <math.h>
long long int CNM(int n,int m)
{
    long long int res=1;
    long long int num1=0,num2=0,num3=0;
    for(int i=1;i<n+1;i++)
    {
        res=res*i;
        if(i==n) num1=res;
        if(i==(n-m)) num2=res;
        if(i==m) num3=res;
    }
    return num1/(num2*num3);
}
int main()
{
    scanf("%d",&cnt);
    for(int i=0;i<cnt;i++)
    {
        int sum=0,now=0,time=0,final=0;
        long long int res=0;
        scanf("%d %d %d %d",&sum,&now,&time,&final);
        {
            if( (-abs(final-now)+time)%2==1 || (-abs(final-now)+time)<0) res=0;
            else if
            ((final<=now && now+(time-abs(final-now))/2<=n && 
                final-(time-abs(final-now))/2>=1)||(final>now &&
                final+(time-abs(final-now)/2<=n && now-(time-abs(final-now))/2>=1))
            {
                int m=(time-abs(final-now))/2;
                int n=time;
                res=CNM(n,m);
            }
            else
            {
                int x1=final>now?final:now;
                int x2=final>now?now:final;
                int denth1=x1-(-abs(final-now)+time)+time;
                int denth2=n-(x1+())
            }
        }
    }
}