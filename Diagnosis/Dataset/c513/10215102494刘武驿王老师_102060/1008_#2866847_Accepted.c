int f(int x,int y)
{
    int tmp1,tmp2;
    int count=0;
    for(int i=0;i<32;i++)
    {
        tmp1=x&1;
        tmp2=y&1;
        if(tmp1!=tmp2) count++;
        x>>=1;
        y>>=1;
    }
    return count;
}
#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        printf("%d\n",f(x,y));
    }
}