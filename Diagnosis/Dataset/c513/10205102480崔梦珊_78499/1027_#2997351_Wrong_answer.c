#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define PI acos(-1)
struct point
{
   double x;
   double y;
   double len;
   double tan;
};
struct point data[10000];
int cmp(void *a,void *b)
{
    struct point poa=*(struct point*)a;
    struct point pob=*(struct point*)b;
    if(poa.tan>pob.tan)
    {
        return 1;
    }
    else
    {
        if(poa.tan==pob.tan)
        {
            if(poa.len>pob.len) return -1;
            else return 1;
        }
        else
        {
            return -1;
        }
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int N;
        scanf("%d",&N);
        printf("case #%d\n",i);
        for(int j=0;j<N;j++)
        {
            scanf("%lf",&data[j].x);
            scanf("%lf",&data[j].y);
            data[j].len=sqrt(data[j].x*data[j].x+data[j].y*data[j].y);
            if(data[j].x>=0&&data[j].y>=0) data[j].tan=atan(data[j].y/data[j].x);
            if(data[j].x>=0&&data[j].y<0) data[j].tan=PI*2+atan(data[j].y/data[j].x);
            if(data[j].x<0) data[j].tan=PI+atan(data[j].y/data[j].x);
        }
        qsort(data,N,sizeof(data[0]),cmp);
        for(int k=0;k<N;k++)
        {
            printf("(%.4lf,%.4lf)\n",data[k].len,data[k].tan);
        }
    }
    return 0;
}
