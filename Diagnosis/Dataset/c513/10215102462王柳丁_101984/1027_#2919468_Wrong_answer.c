#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct coord
{
    float p;
    float angle;
}COORD;

float ANGLE(float a,float b)
{
    float c=sqrt(a*a+b*b);
    float res=0;
    int sign=0;//一个sign一个2/pai
    if(((a>0)&&(b>0))||((a>0)&&(b==0)))sign=0;
    else if(((a<0)&&(b>0))||((a==0)&&(b>0)))sign=1;
    else if(((a<0)&&(b<0))||((a<0)&&(b==0)))sign=2;
    else if(((a>0)&&(b<0))||((a==0)&&(b<0)))sign=3;
    //角度
    if((a!=0)&&(b!=0))
       {
           if(abs(b/c)==0.5)res=1.0/6.0;
            else if(abs(b/a)==1)res=1.0/4.0;
            else if(abs(a/c)==0.5)res=1.0/3.0;
       }
    res=res*3.1416+sign*1.5708;
    return res;
}
int cmp(const void *a,const void *b)
{
    COORD a1=*(COORD *)a;
    COORD b1=*(COORD *)b;
    if(a1.angle==b1.angle)return ((a1.p<b1.p)?1:-1);
    else return ((a1.angle>b1.angle)?1:-1);
}

int main()
{
    int T;
    scanf("%d",&T);
    int i;
    for(i=0;i<T;i++)
    {
        int N,j;
        scanf("%d",&N);
        COORD a[2000];
        float x,y;
        for(j=0;j<N;j++)
        {
            scanf("%f %f",&x,&y);
            a[j].p=sqrt(x*x+y*y);
            a[j].angle=ANGLE(x,y);
        }
        qsort(a,N,sizeof(a[0]),cmp);
        printf("case #%d:\n",i);
        for(j=0;j<N;j++)
        {
            printf("(%.4f,%.4f)\n",a[j].p,a[j].angle);
        }
    }
}
