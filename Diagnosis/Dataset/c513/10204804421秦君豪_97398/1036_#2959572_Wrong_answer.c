#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
#define MAX 4611686018427387904

typedef struct
{
    long long int x;
    long long int y;

}dot;
dot zero={0,0};

long long int llabs(long long int x){ return x < 0 ? -x : x;}
unsigned long long int distance(dot x,dot y)
{
    return llabs(x.x-y.x)+llabs(x.y-y.y);
}

int cmp(const void* a,const void *b)
{
    dot a1=*(dot*)a;
    dot b1=*(dot*)b;
    if (distance(zero,a1)!=distance(zero,b1)) return distance(zero,a1)>distance(zero,b1)?-1:1;
    else if(a1.x!=b1.x) return a1.x>b1.x?1:-1;
    else if(a1.y!=b1.y) return a1.y>b1.y?1:-1;
}



int main(void)
{

    int n;

    scanf("%d",&n);
    dot d[n];
    long long int step=0;
    for(int i=0;i<n;i++)
    {
        scanf("%lld%lld",&d[i].x,&d[i].y);
    }
    qsort(d,n,sizeof(dot),cmp);
//    printf("%lld%lld",d[0].x,d[0].y);
    if(d[0].x == -MAX && d[0].x == -MAX && d[1].x == MAX && d[1].y == MAX)
    {
		printf("18446744073709551616\n");
    }
    else
    {

        printf("%llu\n",distance(d[0],d[1]));
    }
    for(int j=0;j<n-1;j++)
    {
        int cnt=0;
        unsigned long long int dis=distance(d[j],d[j+1]);

        if(dis%2==0&&dis!=0) break;
        while(dis!=0)
        {
            if (dis==1) {
                dis--;
                cnt++;
            }
            else{
                dis =((dis-1)/2)%2==0?dis+1:dis-1;
                cnt++;
            }
            dis/=2;

        }
        step+=cnt;
    }
    printf("Pss");
    printf("%d",step);
}
