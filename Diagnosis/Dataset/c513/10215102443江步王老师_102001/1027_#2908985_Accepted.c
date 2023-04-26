#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define PI 3.14159265
typedef struct Apoint{
        double d;
        double angle;
    }point;

int cmp(const void *_a, const void *_b);

int main()
{
    int T;
    int N;
    int i,j;
    
    scanf("%d",&T);
    for (i=0;i<T;i++){
        scanf("%d",&N);
        double x=0;
        double y=0;
        point *p = (point *)malloc(sizeof(point)*N);
        for (j=0;j<N;j++){//将每个点的x,y坐标分别存入x与y数组中
            scanf("%lf %lf",&x,&y);
            p[j].d=sqrt(pow(x,2)+pow(y,2));
            if (x != 0 && y!=0){
                double tan=y/x;
                if (x>0 && y>0){
                    p[j].angle=atan(tan);
                }
                else if (x<0 && y>0){
                    p[j].angle=atan(tan)+PI;
                }
                else if (x<0 && y<0){
                    p[j].angle=atan(tan)+PI;
                }
                else if (x>0 && y<0){
                    p[j].angle=atan(tan)+2*PI;
                }
            }
            else if(x !=0 && y==0){
                if (x>0){
                    p[j].angle=0;
                }
                else if (x<0){
                    p[j].angle=PI;
                }
            }
            else{
                if (y>0){
                    p[j].angle=fabs(PI/2);
                }
                else if (y<0){
                    p[j].angle=fabs(PI*1.5);
                }
            }
            
        }
        qsort(p,N,sizeof(point),cmp);
        printf("case #%d:\n",i);
        for (j=0;j<N;j++){
            putchar('(');
            printf("%.4lf,%.4lf",p[j].d,p[j].angle);
            putchar(')');
            putchar('\n');
        }
    }
    return 0;
}

int cmp(const void *_a, const void *_b)
{
    point *a=(point *)_a;
    point *b=(point *)_b;
    if ((*a).angle > (*b).angle){
        return 1;
    }
    else if ((*a).angle == (*b).angle && (*a).d < (*b).d){
        return 1;
    }
    return -1;
}