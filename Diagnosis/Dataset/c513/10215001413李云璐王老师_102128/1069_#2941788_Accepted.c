#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int qf(int n)
{
    int a[100],i=0,f=0;
    while(n!=0)
    {
       a[i]=n%10;
       n/=10;
       i++;
    }//i是n的位数，也是a中的元素个数
    for(int k=0;k<i;k++)
    f=f*10+a[k];
    return f;
}

int pd(int n)
{
   int f=qf(n);
    if(n==f) return 1;
    else return 0;
    
}
int main()
{
    int n,cs=0;
    scanf("%d",&n);
    while(pd(n)==0)
    {
        n+=qf(n);
        cs++;
    }
    printf("%d %d",cs,n);
    return 0;
}