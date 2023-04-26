#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct pos
{
  float x;
  float y;
  float dis;
};
int cmp(void *a,void *b)
{
    if(((struct pos *)a)->dis!=((struct pos *)b)->dis) return ((struct pos *)b)->dis-((struct pos *)a)->dis;
    if(((struct pos *)a)->x!=((struct pos *)b)->x) return ((struct pos *)a)->x-((struct pos *)b)->x;
    return ((struct pos *)a)->y-((struct pos *)b)->y;

}
int main()
{
    int n;
    scanf("%d",&n);
    struct pos poss[200];
    float x,y;
    for(int i=0;i<n;i++)
    {
        scanf("%f %f",&poss[i].x,&poss[i].y);
        x=(poss[i].x<0)?-poss[i].x:poss[i].x;
        y=(poss[i].y<0)?-poss[i].y:poss[i].y;
        poss[i].dis=x+y;
    }
    qsort(poss,n,sizeof(poss[0]),cmp);
    long long int step=0;
    float dis,disx,disy,disres;
    disx=poss[1].x-poss[0].x;
    if(disx<0) disx=-disx;
    disy=poss[1].y-poss[0].y;
    if(disy<0) disy=-disy;
    disres=disx+disy;
    for(int i=1;i<n;i++)
    {
        disx=poss[i].x-poss[i-1].x;
        if(disx<0) disx=-disx;
        disy=poss[i].y-poss[i-1].y;
        if(disy<0) disy=-disy;
        dis=disx+disy;
        printf("%.0f\n",dis);
        if(dis==0) continue;
        if(fmod(dis,2)==0)
        {
             printf("%.0f\n%d",disres,step);
             return 0;
        }
        int j=0;
        while(pow(2,j)<=dis) j++;
        step+=j;
    }
     printf("%.0f\n%d",disres,step);
    return 0;
}