#include <stdio.h>
#include <stdlib.h>


int jdz(int x)
{
    if(x>=0) return x;
    else return -x;
}

int way(int n,int p,int m,int t)
{
    int jian=jdz(p-t),re;
    if((p>n)||(p<1)) return 0;
    else if(jian>m)  return 0;
    else if(jian==m) return 1;
    else
    {

        return way(n,p-1,m-1,t)+way(n,p+1,m-1,t);
    }

}

int main()
{
    int cas,i;
    scanf("%d",&cas);
    for(i=0;i<cas;i++)
    {
        int n,p,m,t,re;
        scanf("%d%d%d%d",&n,&p,&m,&t);
        int pand=jdz(p-t)+m;
        if((pand%2)!=0) re=0;
        else if(t>n) re=0;
        else re=way(n,p,m,t);
        printf("%d\n",re);
    }
    return 0;
}
