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
        if(st1->distance > st2->distance)
            return -1;
        else
            return 1;
    }
    else
    {
        if(st1->x != st2->x)
        {
            if(st1->x > st2->x)
                return 1;
            else
                return -1;
        }
        else
        {
            if(st1->y > st2->y)
                return 1;
            else
                return -1;
        }
    }
}

unsigned long long int abs2(long long int x)
{
    if(x < 0)
        return -x;
    else
        return x;
}

int main()
{
    int n,i;
    scanf("%d",&n);
    DIS array[n];
    for(i = 0;i < n;i++)
    {
        scanf("%lld %lld",&array[i].x,&array[i].y);
        array[i].distance = abs2(array[i].x) + abs2(array[i].y);
    }
    qsort(array,n,sizeof(DIS),cmp);
    long long int steps = 0;
    if(abs2(array[0].x - array[1].x) == abs2(array[0].y - array[1].y) && abs2(array[0].x - array[1].x) == 9223372036854775808)
        printf("18446744073709551616\n");
    else
        printf("%llu\n",abs2(array[0].x - array[1].x) + abs2(array[0].y - array[1].y));
    for(i = 1;i < n;i++)
    {
        int flag =0;
        long long int step = 0;
        unsigned long long int distance = abs2(array[i].x - array[i - 1].x) + abs2(array[i].y - array[i - 1].y);
        if(distance == 0);
        else if(distance % 2 == 0)
            break;
        else
        {
            while(distance != 0)
            {
                if(distance % 2 == 0)
                {
                    flag = 1;
                    break;
                }
                else if(distance == 1)
                {
                    step++;
                    break;
                }
                distance = (distance - 1) / 2;
                if(distance % 2 != 0);
                else
                {
                    distance += 1;
                }
                step++;
                
            }
            if(flag)
            {
                break;
            }
            else
            {
                steps += step;
            }
        }
    }
    printf("%lld\n",steps);
    return 0;
}