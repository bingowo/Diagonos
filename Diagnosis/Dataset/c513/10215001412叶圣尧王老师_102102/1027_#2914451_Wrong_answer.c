#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct st 
{
    float x;
    float y;
    float p;
    float q;
};

int cmp(const void*a,const void*b)
{
    struct st*c=(struct st*)a;
    struct st*d=(struct st*)b;
    if(c->q!=d->q)return c->q-d->q;
    else return d->p-c->p;
}

int main()
{
    int T;scanf("%d",&T);int N,i=0,j;
    while(i<T)
    {
        printf("case #%d\n",&i);
        scanf("%d",&N);struct st s[N];
        for(j=0;j<N;j++)
        {
            scanf("%f%f",&s[j].x,&s[j].y);
            s[j].p=sqrt(s[j].x*s[j].x+s[j].y*s[j].y);
            s[j].q=atan(s[j].y/s[j].x);
        }
        qsort(s,N,sizeof(s[0]),cmp);
        for(j=0;j<N;j++)
            printf("(%.4f,%.4f)\n",s[j].p,s[j].q);
        i++;
    }
}