#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define pi 3.1415926


struct point{
    double x;
    double y;
};


int main()
{
    int m;
    int cmp(const void *a1,const void *b1);
    scanf("%d",&m);
    for(int z=0;z<m;z++)
    {
        int num;
        scanf("%d",&num);
        struct point s[1000];
        for(int i=0;i<num;i++)
            {
                double a,b;
                scanf("%lf %lf",&a,&b);
                double sum=pow(a,2)+pow(b,2);
                s[i].x=sqrt(sum);


                //接下来输入极角的值

                if(a==0&&b==1) s[i].y=pi/2;

                else if(a==0&&b==-1) s[i].y=3*pi/2;

                else if(a>0&&b>=0)
                {
                    s[i].y=atan(b/a);
                }
                else if(a>0&&b<=0)
                {
                    s[i].y=2*pi+atan(b/a);
                }
                else if(a<0&&b<=0)
                {
                    s[i].y=pi+atan(b/a);
                }
                else if(a<0&&b>=0)
                {
                    s[i].y=pi+atan(b/a);
                }
            }
        qsort(s,num,sizeof(struct point),cmp);

        printf("case #%d:\n",z);

        for(int u=0;u<num;u++)
                printf("(%.4f,%.4f)\n",s[u].x,s[u].y);
    }
    return 0;
}

int cmp(const void *a1,const void *b1)
{
    struct point a=*(struct point*)a1;
    struct point b=*(struct point*)b1;
    if(a.y>b.y) return 1;
    else if(a.y<b.y) return -1;
    else {
            if(a.x>b.x) return -1;
            else return 1;
    }
}
