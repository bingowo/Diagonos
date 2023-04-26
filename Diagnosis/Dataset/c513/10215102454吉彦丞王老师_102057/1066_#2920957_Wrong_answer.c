#include<stdio.h>
#include<math.h>
int C(int m,int n)
{
    int t=1;
    for(int i=1;i<n+1;i++)
    {
        t=t*(m+1-i)/i;
    }
    return t;
}
int T(int n,int m,int p,int t)
{
    if(abs(p-t)>m)
    {
        return 0;
    }
    else if(abs(p-t)==m)
    {
        return 1;
    }
    else
    {
        if((m-abs(p-t))%2==1)
        {
            return 0;
        }
        else
        {
            return C(m,(m+abs(p+t))/2);
        }
    }
}
int main()
{
    int number;
    scanf("%d",&number);
    for(int i=0;i<number;i++)
    {
        int n,p,m,t;
        scanf("%d%d%d%d",&n,&p,&m,&t);
        printf("%d\n",T(n,m,p,t));
    }
    return 0;
}