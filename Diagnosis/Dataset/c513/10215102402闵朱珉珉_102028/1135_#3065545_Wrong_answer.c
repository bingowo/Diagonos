#include <stdio.h>
long long q[501]={0};
void change (int n)
{
    if (n==0||n==1)
    {
        q[0]=1;
        q[1]=1;
    }
    else if (n==2) q[2]=2;
    else if (n==3) q[3]=3;
    else if (n==4) q[4]=6;
    else if (n==5) q[5]=10;
    else if(n%2==0)
    {
        change(n/2);change(n/2-1);change(n/2-2);change(n/2-3);
        q[n]=q[n/2]*q[n/2]+q[n/2-1]*q[n/2-1]+q[n/2-2]*q[n/2-2]+q[n/2-1]*q[n/2-3]*2;
    }
    else
    {
        change(n/2);change(n/2-1);change(n/2-2);change(n/2-3);
        q[n]=q[n/2]*q[n/2]+q[n/2]*q[n/2-1]*2+q[n/2-1]*q[n/2-2]*2+q[n/2]*q[n/2-3]*2;
    }

}
int main()
{
    int n;
    scanf("%d",&n);
    change(n);
    printf("%lld",q[n]);
}
