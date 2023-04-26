#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>

typedef unsigned long long ull;
typedef long long ll;

ull ullabs(ll p)//将longlong 转化为ull
{
if (p>=0)return (ull)p;
else return ((ull)(-(p+1)))+1;
}

int cmp(const void*p1,const void*p2)
{
     long long*p_1 = (long long*)p1;
     long long*p_2 = (long long*)p2;
     if(ullabs(p_1[0])+ullabs(p_1[1]) < ullabs(p_2[0])+ullabs(p_2[1]))return 1;
     else if(ullabs(p_1[0])+ullabs(p_1[1]) == ullabs(p_2[0])+ullabs(p_2[1]))
     {
         if(p_1[0]>p_2[0])return 1;
         else if(p_1[0] == p_2[0])
         {
             return (p_1[1]<p_2[1])?-1:1;
         }
         else return -1;
     }
     else return -1;
}


int judge(long long p1[2],long long p2[2])//判断是否可以到达，返回所需步数
{
    ull length =0,x,y;
    if((p1[0]>>63)^(p2[0]>>63))x = ullabs(p1[0])+ullabs(p2[0]);
    else x = ullabs(p1[0] - p2[0]);
    if((p1[1]>>63)^(p2[1]>>63))y = ullabs(p1[1])+ullabs(p2[1]);
    else y = ullabs(p1[1] - p2[1]);
    length = x+y;
    int step = 0;
    if(!(length%2)&&length!=0)return -1;
    else if(length ==0)return 0;
    else
    {
        do {step ++;}
        while(length/=2);
        return step;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int i;
    ll p[200][2];
    for( i = 0;i< n;i++)
    {
        scanf("%lld%lld",&p[i][0],&p[i][1]);
    }
    qsort(p,n,sizeof(long long)*2,cmp);
    ll num = 0;
    for(int q=0;q<n-1;q++)
    {
    int z  = judge(p[q],p[q+1]);
    if(z == -1)break;
    else num +=z;
    }
    ull length,x,y;
     if((p[0][0]>>63)^(p[1][0]>>63)) x= ullabs(p[0][0])+ullabs(p[1][0]);
    else x = ullabs(p[0][0] - p[1][0]);
    if((p[0][1]>>63)^(p[1][1]>>63))y = ullabs(p[0][1])+ullabs(p[1][1]);
    else y = ullabs(p[0][1] - p[1][1]);
    length = x+y;

    if(length < x)printf("18446744073709551616\n%lld",num);
    else printf("%llu\n%lld",length,num);
    return 0;
}
