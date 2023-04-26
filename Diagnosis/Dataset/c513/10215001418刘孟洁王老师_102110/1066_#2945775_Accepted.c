#include <stdio.h>
#include <stdlib.h>
//16号楼只是告诉如果不是1号楼或者最后一号楼有两种情况，意思即一分钟只能够到达旁边的一栋楼；
int ways(int n,int p,int m,int t)
{
   if(m == 0 && p == t)return 1;//递归结束条件1：若时间减少到0，楼层到达所定楼
   else if(m == 0 && p != t)return 0;//递归结束条件2：时间减少到0，但没有达到该楼
   if(p == 1)return ways(n,p+1,m-1,t);
   else if(p == n)return ways(n,n-1,m-1,t);
   else return ways(n,p+1,m-1,t)+ways(n,p-1,m-1,t);
}

int main()
{
    int n,p,m,t,cas,i;
    scanf("%d",&cas);
    for(i = 0; i < cas; i++)
    {
        scanf("%d%d%d%d",&n,&p,&m,&t);
        printf("%d\n",ways(n,p,m,t));
    }
    return 0;
}
