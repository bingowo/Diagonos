#include<stdio.h>
#include<math.h>
#include<stdlib.h>

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
        double *x = (double *)malloc(sizeof(double)*N);//存储x坐标
        double *y = (double *)malloc(sizeof(double)*N);//存储y坐标
        point *p = (point *)malloc(sizeof(point)*N);
        for (j=0;j<N;j++){//将每个点的x,y坐标分别存入x与y数组中
            scanf("%f %f",(x+j),(y+j));
            p[j].d=sqrt(pow(*(x+j),2)+pow(*(y+j),2));
            p[j].angle=asin(*(y+j)/p[j].d);
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