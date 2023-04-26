#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int x;
    int y;

}dot;
dot zero={0,0};

int distance(dot x,dot y)
{
    return abs(x.x-y.x)+abs(x.y-y.y);
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
    int step=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&d[i].x,&d[i].y);
    }
    qsort(d,n,sizeof(dot),cmp);
    printf("%d\n",distance(d[0],d[1]));

    for(int j=0;j<n-1;j++)
    {
        int cnt=0;
        int dis=distance(d[j],d[j+1]);
        if(dis%2==0) break;
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
//            printf("%d\n",dis);
        }
        step+=cnt;
    }
    printf("%d",step);
}
