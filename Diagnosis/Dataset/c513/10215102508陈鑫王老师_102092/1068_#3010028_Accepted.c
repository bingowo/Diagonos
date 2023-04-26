#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int ch(int m,int n)
{
    if(m>n)return 0;
    else if (m==n)return 1;
    else
    {
        return 2*ch(m,n-1)+pow(2,n-m-1)-ch(m,n-m-1);
    }

}
int main()
{
    int m,n;
    while(scanf("%d %d",&n,&m)&&m!=-1&&n!=-1)
    {
        printf("%d\n",ch(m,n));
    }
    return 0;
}