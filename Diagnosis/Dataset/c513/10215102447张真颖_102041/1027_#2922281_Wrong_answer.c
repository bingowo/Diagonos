#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int cmp(const void*a,const void*b)
{
    double *pa=*(double(*)[2])a,*pb=*(double(*)[2])b;
    if(atan2(pa[1],pa[0])>atan2(pb[1],pb[0])) return 1;
    else if(atan2(pa[1],pa[0])<atan2(pb[1],pb[0])) return -1;
    else
    {
        if((pa[0]*pa[0]+pa[1]*pb[1])>(pb[0]*pb[0]+pb[1]*pb[1])) return -1;
        else if((pa[0]*pa[0]+pa[1]*pb[1])<(pb[0]*pb[0]+pb[1]*pb[1])) return 1;
        return 0;
    }

}

int main()
{
    int T=0;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int N=0;
        double pos[1000][2]={0};
        scanf("%d",&N);
        for(int i=0;i<N;i++)
            scanf("%lf%lf",&pos[i][0],&pos[i][1]);
        qsort(pos,N,sizeof(pos[0]),cmp);
        printf("case #%d:\n",i);
        for(int i=0;i<N;i++)
        {
            printf("(%.4lf,%.4lf)\n",sqrt(pos[i][0]*pos[i][0]+pos[i][1]*pos[i][1]),atan2(pos[i][1],pos[i][0]));
        }
    }
    return 0;
}
