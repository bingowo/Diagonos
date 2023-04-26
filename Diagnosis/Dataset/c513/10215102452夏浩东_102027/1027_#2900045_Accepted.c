#include <stdio.h>
#include <math.h>
#include <stdlib.h>
struct JZB{
  double x;
  double y;
  double lon;
  double ang;
};
int cmp(const void *a,const void *b)
{
    struct JZB* A=(struct JZB*)a;
    struct JZB* B=(struct JZB*)b;
    if(A->ang > B->ang) return 1;
    else if(A->ang < B->ang) return -1;
    else 
	{
		if(B->lon > A->lon) return 1;
		else return -1;
	}
}
int main()
{
    int cnt=0;
    scanf("%d",&cnt);
    for(int i=0;i<cnt;i++)
    {
        int num=0;
        struct JZB L[1000];
        scanf("%d",&num);
        for(int k=0;k<num;k++)
        {
            scanf("%lf %lf",&L[k].x,&L[k].y);
            L[k].ang=atan2(L[k].y,L[k].x);
            L[k].lon=sqrt(L[k].x*L[k].x+L[k].y*L[k].y);
            if(L[k].ang<0) L[k].ang+=8*atan(1.0);
        }
        qsort(L,num,sizeof(struct JZB),cmp);
        printf("case #%d:\n",i);
        for(int k=0;k<num;k++)
        {
            printf("(%.4f,%.4f)\n",L[k].lon,L[k].ang);
        }
    }
    return 0;
}