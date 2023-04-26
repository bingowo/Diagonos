#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct
{
    double x;
    double y;
    double r;
    double angle;
}DATA;

int cmp(const void *a , const void *b)
{     //angle升序，r降序
    DATA *x = (DATA*)a;
    DATA *y = (DATA*)b;
    int m,n;
    m = (int) (x->angle - y->angle);
    n = (int) (y->r - x->r);
    if(x->angle != y->angle)
        return m;
    else
        return n;
}

int main()
{
    int T;           //问题数
    scanf("%d",&T); 
    int index;
    for(index = 0;index < T;index++)    //一个问题
    {
        int N; //点的个数
        scanf("%d",&N);
        DATA POINT[N];
        int i;
        for(i=0;i<N;i++)             //输入一个点的信息
        {
            double temp;
            scanf("%lf",&POINT[i].x);
            scanf("%lf",&POINT[i].y);
            POINT[i].r = sqrt(POINT[i].x*POINT[i].x + POINT[i].y*POINT[i].y) ;
            temp = asin(POINT[i].x / POINT[i].r);
            POINT[i].angle = (temp>0 ? temp : -temp);
        }
        qsort(POINT , N , sizeof(DATA) , cmp);
        printf("case #%d:\n",index);
        for(i=0;i<N;i++)
        {
            printf("(%.4lf,%.4lf)\n",POINT[i].r,POINT[i].angle);
        }
    }
    return 0;
}