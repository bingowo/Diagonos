#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    long long int x;
    long long int y;
    unsigned long long int distance;
}DIS;

int cmp(const void*s1,const void*s2)
{
    DIS*st1,*st2;
    st1 = (DIS*)s1,st2 = (DIS*)s2;
    if(st1->distance != st2->distance)
    {
        return st2->distance - st1->distance;
    }
    else
    {
        if(st1->x != st2->x)
            return st1->x - st2->x;
        else
            return st1->y - st2->y;
    }
}

int main()
{
    int n,i;
    scanf("%d",&n);
    DIS*array = (DIS*)malloc(n*sizeof(DIS));
    for(i = 0;i < n;i++)
    {
        scanf("%lld %lld",array[i].x,array[i].y);
        array[i].distance = abs(array[i].x) + abs(array[i].y);
    }
    qsort(array,n,sizeof(DIS*),cmp);
    long long int steps = 0;
    printf("%lld\n",abs(array[0].x - array[1].x) + abs(array[0].y - array[1].y));
    for(i = 1;i < n;i++)
    {
        int flag =0;
        long long int step = 0;
        long long int distance = abs(array[i].x - array[i - 1].x) + abs(array[i].y - array[i - 1].y);
        if(distance % 2 == 0)
            continue;
        else
        {
            while(distance != 0)
            {
                if(distance % 2 == 0)
                {
                    flag = 1;
                    break;
                }
                if(((distance - 1) / 2) % 2 != 0)
                {
                    distance = (distance - 1) / 2;
                }
                else
                {
                    distance = (distance + 1) / 2;
                }
                step++;
            }
            if(!flag)
            {
                steps += step;
            }
        }
    }
    printf("%lld\n",steps);
    return 0;
}