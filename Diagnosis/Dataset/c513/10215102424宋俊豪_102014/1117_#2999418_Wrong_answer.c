#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
typedef struct{long long x;long long y;long long m;}list;
long long max(long long x,long long y)
{
    if(x>y)
        return x;
    else
        return y;
}
int cmp(const void *a, const void *b)
{
    list* x1=(list*)a;
    list* y1=(list*)b;
    if(x1->m<y1->m)
    {
        return -1;
    }
    else if(x1->m>y1->m)
    {
        return 1;
    }
    else
    {
        if(x1->x>y1->x)
        {
            return 1;
        }
        else if(x1->x<y1->x)
            return  -1;
        else
        {
            if(x1->y>y1->y)
                return -1;
            else
                return 1;
        }
    }
}

int main()
{
   long long x,y;
   scanf("%lld%lld",&x,&y);
   int n;
   scanf("%d",&n);
   list *t=(list*)malloc(n*sizeof(list));
   for(int i=0;i<n;i++)
   {
       scanf("%lld%lld",&t[i].x,&t[i].y);
       t[i].m=max(llabs(t[i].x-x),llabs(t[i].y-y));
   }
   qsort(t,n,sizeof(list),cmp);
   printf("%lld\n%lld %lld",t[0].m,t[0].x,t[0].y);
   free(t);
}
