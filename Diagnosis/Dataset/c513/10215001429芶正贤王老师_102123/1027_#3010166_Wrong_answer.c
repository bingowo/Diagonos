#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.1415926

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
    m = (int)((x->angle - y->angle)*100000);
    n = (int)((y->r - x->r)*100000);
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
            double X,Y;
            scanf("%lf",&POINT[i].x);
            scanf("%lf",&POINT[i].y);
            X = POINT[i].x;
            Y = POINT[i].y;
            POINT[i].r = sqrt(X*X + Y*Y);
            if(POINT[i].r != 0)
            {
                temp = asin(fabs(Y) / POINT[i].r);
            	if( X > 0  && Y > 0 )          //1
                	POINT[i].angle = temp;
            	else if( X < 0  && Y > 0)   //2
                	POINT[i].angle = PI - temp;
            	else if(X < 0 && Y < 0)      //3          
                	POINT[i].angle = PI + temp;
            	else if(X > 0 && Y < 0)          //4
                	POINT[i].angle = 2*PI - temp;
            
            	else if( X > 0  && Y == 0)
                	POINT[i].angle = 0;
            	else if(X < 0 && Y == 0)
                	POINT[i].angle = PI;
            	else if(X == 0 && Y > 0)
                	POINT[i].angle = PI/2;
            	else if(X == 0 && Y < 0)
                	POINT[i].angle = 3*PI/2;
            }
            else
                POINT[i].angle = 0;
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