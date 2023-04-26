#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define pi 3.1415926
typedef struct{double p;double ti;}list;
int cmp(const void *a,const void *b)
{
    list *ax=(list*)a;list *bx=(list*)b;
    if (fabs((ax->ti)-(bx->ti))>0.00001)
        if((ax->ti)-(bx->ti)>0)
            return 1;
        else 
        return -1;
    else
         return bx->p-ax->p;
}
int main()
{
    int n;double x,y;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    { int n1=0;
      scanf("%d",&n1);
      list *t=(list*)malloc(sizeof(list)*n1);
      for (int j=0;j<n1;j++)
      {
            scanf("%lf%lf",&x,&y);

            t[j].p=sqrt(x*x+y*y);
            t[j].ti=atan2(y,x);
            if (t[j].ti<0)
                t[j].ti+=2*pi;
      }
      qsort(t,n1,sizeof(t[0]),cmp);
      printf("case #%d:\n",i);
      for(int q=0;q<n1;q++)
      printf("(%.4f,%.4f)\n",t[q].p,t[q].ti);
      free(t);
    }
    return 0;
}

