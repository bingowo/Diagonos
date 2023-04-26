#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct JZB{double r;double jiaodu;}Ji;

int cmp(const void*a,const void *b)
{
    Ji *p1=(Ji*)a;
    Ji *p2=(Ji*)b;
    if(p1->jiaodu<p2->jiaodu)
    {
        return -1;
    }
    else if(p1->jiaodu>p2->jiaodu)
    {
        return 1;
    }
    else if(p1->r<p2->r)
    {
        return 1;
    }
    else if(p1->r>p2->r)
    {
        return -1;
    }
}

int main()
{
    int count,count1,number;
    double x,y;
    scanf("%d",&count);
    count1=count;
    while(count--)
    {
        Ji S[1000];
        Ji *p=S;
        scanf("%d",&number);
        for(int i=0;i<number;i++)
        {
            scanf("%lf %lf",&x,&y);
            S[i].r=sqrt(x*x+y*y);
            if(y<0&&x>0)
            {
                S[i].jiaodu=2*3.1415926+atan(y/x);
            }
            else if(x<0&&y>0)
            {
                S[i].jiaodu=3.1415926+atan(y/x);
            }
            else if(y==0&&x>0)
            {
                S[i].jiaodu=atan(y/x);
            }
            else if(x==0&&y>0)
            {
                S[i].jiaodu=atan(y/x);
            }
            else if(y==0&&x<0)
            {
                S[i].jiaodu=3.1415926+atan(y/x);
            }
            else if(x==0&&y<0)
            {
                S[i].jiaodu=3.1415926-atan(y/x);
            }
            else if(y<0&&x<0)
            {
                S[i].jiaodu=3.1415926+atan(y/x);
            }
            else
            S[i].jiaodu=atan(y/x);
        }
        qsort(p,number,sizeof(S[0]),cmp);
        printf("case #%d:\n",count1-count-1);
    for(int i=0;i<number;i++)
    {
        printf("(%.4lf,%.4lf)\n",S[i].r,S[i].jiaodu);
    }
    }


}
