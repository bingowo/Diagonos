#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {long long int x;long long int y;long long int sum;}D;

int cmp(const void *p1,const void *p2)
{
    D* a=(D*)p1;D* b=(D*)p2;
    if(a->sum>b->sum)return -1;
    else if(a->sum<b->sum) return 1;
    else if(a->x<b->x)return -1;
    else if(a->x>b->x)return 1;
    else if(a->y<b->y)return -1;
    else if(a->y>b->y)return 1;
}

int main()
{
    int n;long long int temp;
    scanf("%d",&n);
    D A[150];
    D*p=A;
    for(int i=0;i<n;i++)
    {
        scanf("%lld %lld",&A[i].x,&A[i].y);
        if(A[i].x<=0&&A[i].y<=0)A[i].sum=-A[i].x-A[i].y;
        else if(A[i].x>=0&&A[i].y<=0)A[i].sum=A[i].x-A[i].y;
        else if(A[i].x<=0&&A[i].y>=0)A[i].sum=-A[i].x+A[i].y;
        else A[i].sum=A[i].x+A[i].y;
    }
    qsort(p,n,sizeof(A[0]),cmp);
    temp=abs(A[0].x-A[1].x)+abs(A[0].y-A[1].y);
    printf("%lld\n",temp);

    /*for(int i=0;i<n;i++)
    {
        printf("%lld %lld\n",A[i].x,A[i].y);
    }*/

    long long int count=0;
    for(int i=0;i<n-1;i++)
    {
        long long int t,t1,count1=0,count2=0;
        if((A[i].x-A[i+1].x)%2==0)
        {
            t=A[i].y-A[i+1].y;
            if(t<0)t=-t;
            t1=A[i].x-A[i+1].x;
            if(t1<0)t1=-t1;
            t=t1+t;
            if(t%2==0)break;
            t=t+1;
            if((t-2)%4!=0);
            else
            {
                while(1)
                {
                    if(t<pow(2,count2)&&t>=pow(2,count2-1))break;
                    count2++;
                }
            }
            t=t-2;
            if((t-2)%4!=0);
            else
            {
                while(1)
                {
                    if(t<pow(2,count1)&&t>=pow(2,count1-1))break;
                    count1++;
                }
            }

        }
        else
        {
            t=A[i].x-A[i+1].x;
            if(t<0)t=-t;
            t1=A[i].y-A[i+1].y;
            if(t1<0)t1=-t1;
            t=t1+t;
            if(t%2==0)break;
            t=t+1;
            if((t-2)%4!=0);
            else
            {
                while(1)
                {
                    if(t<pow(2,count2)&&t>=pow(2,count2-1))break;
                    count2++;
                }
            }
            t=t-2;
            if((t-2)%4!=0);
            else
            {
                while(1)
                {
                    if(t<pow(2,count1)&&t>=pow(2,count1-1))break;
                    count1++;
                }
            }


        }
        if(count1==0&&count2==0)break;
        else if(count1==0)count=count+count2;
        else if(count2==0)count=count+count1;
    }
    printf("%lld",count);
}



/*while(1)
            {
                if(t<pow(2,count2)&&t>=pow(2,count2-1))break;
                count2++;
            }
            t=A[i].y-A[i+1].y;
            if(t<0)t=-t;
            if(t%2!=0)break;
            if((long long int)(t-pow(2,count2-1))%(long long int)pow(2,count2)!=0)break;
            count=count2+count;count2=0;
            t1=(long long int)t/(long long int)pow(2,count);
            while(1)
            {
                if(t<pow(2,count1)&&t>=pow(2,count1-1))break;
                count1++;
            }
            count=count+count1;count1=0;*/
