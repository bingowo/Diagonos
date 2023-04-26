#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct data
{
    long long int a;
    int n;
};
int cmp(const void *a,const void *b)
{
    struct data d1,d2;
    d1=*((struct data *)a);
    d2=*((struct data *)b);
    if(d2.n!=d1.n)
    {
        return d2.n-d1.n;
    }
    else
    {
        if(d1.a>d2.a)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
}
int main()
{
    int number;
    scanf("%d",&number);
    int b[number];
    struct data p[number][10000];
    for(int i=0;i<number;i++)
    {
        scanf("%d",&b[i]);
        for(int j=0;j<b[i];j++)
        {
            scanf("%lld",&p[i][j].a);
            long long int start=1;
            p[i][j].n=0;
            for(int k=0;k<64;k++)
            {
                if(p[i][j].a&start!=0)
                {
                    p[i][j].n++;
                }
                start=start<<1;
            }
            
        }
        
    }
    for(int t=0;t<number;t++)
    {
    	qsort(p,b[t],sizeof(p[t][0]),cmp);
        printf("case #%d:\n",t);
        for(int j=0;j<b[t]-1;j++)
        {
            printf("%lld ",p[t][j].a);
        }
        printf("%lld\n",p[t][b[t]-1].a);
        
    }
    return 0;
}