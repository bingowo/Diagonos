#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct{
    long long int x;
    long long int y;
    long long int distance_x;
    long long int distance_y;
    long long int manhaton;
}DOT;
int cmp(const void*a,const void*b)
{
    DOT*st1,*st2;
    st1 = (DOT*)a,st2 = (DOT*)b;
    return st2->manhaton - st1->manhaton;
}
long long int absolute(long long int x)
{
    if(x < 0)
        return -x;
    else
        return x;
}
int main()
{
    long long int between_dots;
    int steps = 0;
    int n,i;
    scanf("%d",&n);
    DOT dot[n];
    for(i = 0;i < n;i++)
    {
        scanf("%lld %lld",&dot[i].x,&dot[i].y);
        dot[i].distance_x = absolute(dot[i].x);
        dot[i].distance_y = absolute(dot[i].y);
        dot[i].manhaton = dot[i].distance_x + dot[i].distance_y;
    }
    qsort(dot,n,sizeof(dot[0]),cmp);
    for(i = 0;i < n-1;i++)
    {
        between_dots = absolute(dot[i].distance_x - dot[i+1].distance_x) + absolute(dot[i].distance_y - dot[i+1].distance_y);
        if(between_dots%2 == 1)
            {
                int j = 0;
                while((int)pow(2,j) < between_dots)
                    j++;
                steps += j;

            }
        else
            break;
    }
    printf("%lld %d",absolute(dot[0].distance_x - dot[1].distance_x) + absolute(dot[0].distance_y - dot[1].distance_y),steps);
    return 0;
}
