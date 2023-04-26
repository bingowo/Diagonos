#include <stdio.h>
#include <stdlib.h>
int geshu(int a,int b)
{
    unsigned int c;
    int ret=0;
    c=a^b;
    while(c!=0)
    {
        if(c&1)ret=ret+1;
        c=c>>1;
    }
    return ret;

}
int main()
{
    int t,c;
    scanf("%d",&t);
    long long int a[t][2];
    c=0;
    while(c<t)
    {
       scanf("%lld%lld",&a[c][0],&a[c][1]);
       c+=1;
    }
    for(int i=0;i<t;i++)
    {
        printf("%d\n",geshu(a[i][0],a[i][1]));
    }

    return 0;


}