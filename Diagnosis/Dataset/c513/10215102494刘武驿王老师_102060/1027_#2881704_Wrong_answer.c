#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct polar
{
  double len;
  double ang;
};
struct reg
{
  double x;
  double y;
};
int cmp(void*a,void*b)
{
    if(((struct polar*)a)->ang!=((struct polar*)b)->ang) 
    return ((struct polar*)a)->ang-((struct polar*)b)->ang;
    else return  ((struct polar*)b)->len-((struct polar*)a)->len;
}
int main()
{
    int sum,n;
    scanf("%d",&sum);
    struct reg ori[1000];
    struct polar res[1000];
    for(int i=0;i<sum;i++)
    {
        scanf("%d",&n);
        for(int j=0;j<n;j++) scanf("%lf %lf",&ori[j].x,&ori[j].y);
        for(int j=0;j<n;j++)
        {
            res[j].ang=atan2(ori[j].y,ori[j].x);
            res[j].len=sqrt(pow(ori[j].x,2)+pow(ori[j].y,2));
        }
        qsort(res,n,sizeof(struct polar),cmp);
        printf("case #%d:\n",i);
        for(int x=0;x<n;x++) 
        {
            printf("(%.4lf,%.4lf)\n",res[x].len,res[x].ang);
        }
    }
}