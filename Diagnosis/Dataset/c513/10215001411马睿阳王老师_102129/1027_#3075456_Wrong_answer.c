#include<stdio.h>
#include<string.h>
#include<math.h>
#define Pi 3.1415926
typedef struct
{
    double p;double u;
}point;

int cmp(const void*a,const void*b)
{
    point c=*(point *)a;
    point d=*(point *)b;
    if(c.u<d.u) return -1;
    else if(c.u>d.u) return 1;
    else return d.p-c.p;
}

int main()
{
    int i,j,T,N;
    double x,y;
    point *s;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        scanf("%d",&N);
        s=(point*)malloc(N*sizeof(point));
        for(j=0;j<N;j++)
        {
            scanf("%lf%lf",&x,&y);
            s[j].p=sqrt(pow(x,2)+pow(y,2));//sqrt表示开平方根
            if(y>=0)
            {
                if(x>0) s[j].u=atan(y/x);
                else if(x<0) 
                {x=-x;
                 s[j].u=atan(y/x);
                }
                else if(x==0) s[j].u=Pi/2;

            }
            else
            {
                if(x<0) s[j].u=atan(y/x)+Pi;
                else if(x>0) s[j].u=atan(y/x)+2*Pi;
                
                else if(x==0) s[j].u=3*Pi/2;//反三角函数
            }
        }
        qsort(s,N,sizeof(point),cmp);
        for(j=0;j<N;j++)
            printf("(%.4lf,%.4lf)\n",s[j].p,s[j].u);
    }
    free(s);//别忘记释放
    return 0;
}
