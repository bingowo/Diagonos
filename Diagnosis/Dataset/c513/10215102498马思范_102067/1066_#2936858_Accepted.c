#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int floor(int n,int p,int m,int t)
{
    if(m==0&&p==t)
        return 1;
    else if(m==0&&p!=t)
        return 0;
    if(p==1)
    {
        return floor(n,p+1,m-1,t);
    }
    else if(p==n)
    {
        return floor(n,p-1,m-1,t);
    }
    else
    {
        return floor(n,p-1,m-1,t)+floor(n,p+1,m-1,t);
    }

}
int main()
{
    int cas;
    scanf("%d",&cas);
    for(int i=0;i<cas;i++)
    {
        int n,p,m,t;
        scanf("%d%d%d%d",&n,&p,&m,&t);
        printf("%d\n", floor(n,p,m,t));
    }
    return 0;
}