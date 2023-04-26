#include<stdio.h>
#include<string.h>
struct data
{
    int x;
    long long int y[x];
    int z;
}
int main()
{
    int number;
    struct data p[number]
    scanf("%d",&number);
    for(int i=0;i<number;i++)
    {
        scanf("%d",&p[i].x);
        p[i].z=1;
        for(int j=0;j<x;j++)
        {
            int d=1;
            scanf("%lld",&p[i].y[j]);
            for(int t=0;t<64;t++)
            {
                if(p[i].y[j]&d)
                {
                    p[i].z++;
                }
                d=d<<1;
            }
            int cmp(const void *a,const void *b)
            {
                struct data e1,e2;
                e1=*((struct data *)a);
                e2=*((struct data *)b);
                if(e2.z!=e1.z)
                {
                    return e2.z-e1.z;
                }
                else
                {
                    if(e1.y[j]>d2.y[j])
                    {
                        return 1;
                    }
                    else
                    {
                        return -1;
                    }
                }
            }
            qsort(p,x,sizeof(p[i]),cmp);
        }
        
    }
    for(int i=0;i<number;i++)
    {
        printf("case #%d:\n",i);
        for(int j=0;j<p[i].x)
        {
            printf("%lld",p[i].y[j]);
        }
    }
    return 0;

}