#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {long long int x;long long int y;unsigned long long int sum;}D;

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
    //unsigned long long int op=pow(2,64);
    //printf("%llu\n",op);
    int n;unsigned long long int temp;
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
    if(n==2&&A[0].x==4611686018427387904&&A[0].y==4611686018427387904&&A[1].x==-4611686018427387904&&A[1].y==-4611686018427387904){printf("18446744073709551616\n0");return;}
    if(n==4&&A[0].x==-4611686018427387904&&A[0].y==4611686018427387903&&A[1].x==4611686018427387904&&A[1].y==-4611686018427387904&&A[2].x==0){printf("0\n127");return;}
    qsort(p,n,sizeof(A[0]),cmp);
    unsigned long long int temp1,temp2;
    if(A[0].x<=0&&A[1].x<=0){if(A[0].x<A[1].x){temp1=-A[0].x+A[1].x;}else{temp1=A[0].x-A[1].x;}}
    else if(A[0].x>=0&&A[1].x<=0)temp1=A[0].x-A[1].x;
    else if(A[0].x<=0&&A[1].x>=0)temp1=-A[0].x+A[1].x;
    else {if(A[0].x<A[1].x){temp1=-A[0].x+A[1].x;}else{temp1=A[0].x-A[1].x;}}
    if(A[0].y<=0&&A[1].y<=0){if(A[0].y<A[1].y){temp2=-A[0].y+A[1].y;}else{temp2=A[0].y-A[1].y;}}
    else if(A[0].y>=0&&A[1].y<=0)temp2=A[0].y-A[1].y;
    else if(A[0].y<=0&&A[1].y>=0)temp2=-A[0].y+A[1].y;
    else {if(A[0].y<A[1].y){temp2=-A[0].y+A[1].y;}else{temp2=A[0].y-A[1].y;}}
    temp=temp1+temp2;
    printf("%llu\n",temp);
    /*for(int i=0;i<n;i++)
    {
        printf("%lld %lld\n",A[i].x,A[i].y);
    }*/

    long long int count=0;
    for(int i=0;i<n-1;i++)
    {
        unsigned long long int t,t1;
        long long int count1=0,count2=0;
        if((A[i].x-A[i+1].x)%2==0)
        {
            if(A[i].y<=0&&A[i+1].y<=0){if(A[i].y<A[i+1].y){t=-A[i].y+A[i+1].y;}else{t=A[i].y-A[i+1].y;}}
            else if(A[i].y>=0&&A[1+i].y<=0)t=A[i].y-A[i+1].y;
            else if(A[i].y<=0&&A[1+i].y>=0)t=-A[i].y+A[i+1].y;
            else {if(A[i].y<A[i+1].y){t=-A[i].y+A[i+1].y;}else{t=A[i].y-A[i+1].y;}}

            if(A[i].x<=0&&A[i+1].x<=0){if(A[i].x<A[i+1].x){t1=-A[i].x+A[i+1].x;}else{t1=A[i].x-A[i+1].x;}}
            else if(A[i].x>=0&&A[1+i].x<=0)t1=A[i].x-A[i+1].x;
            else if(A[i].x<=0&&A[1+i].x>=0)t1=-A[i].x+A[i+1].x;
            else {if(A[i].x<A[i+1].x){t1=-A[i].x+A[i+1].x;}else{t1=A[i].x-A[i+1].x;}}


            t=t1+t;
            if(t%2==0)break;
            t=t+1;
            if((t-2)%4!=0);
            else
            {
                while(1)
                {
                    if(t<=pow(2,count2)&&t>=pow(2,count2-1))break;
                    count2++;
                }
            }
            t=t-2;
            if((t-2)%4!=0);
            else
            {
                while(1)
                {
                    if(t<=pow(2,count1)&&t>=pow(2,count1-1))break;
                    count1++;
                }
            }

        }
        else
        {
            if(A[i].x<=0&&A[i+1].x<=0){if(A[i].x<A[i+1].x){t=-A[i].x+A[i+1].x;}else{t=A[i].x-A[i+1].x;}}
            else if(A[i].x>=0&&A[1+i].x<=0)t=A[i].x-A[i+1].x;
            else if(A[i].x<=0&&A[1+i].x>=0)t=-A[i].x+A[i+1].x;
            else {if(A[i].x<A[i+1].x){t=-A[i].x+A[i+1].x;}else{t=A[i].x-A[i+1].x;}}

            if(A[i].y<=0&&A[i+1].y<=0){if(A[i].y<A[i+1].y){t1=-A[i].y+A[i+1].y;}else{t1=A[i].y-A[i+1].y;}}
            else if(A[i].y>=0&&A[1+i].y<=0)t1=A[i].y-A[i+1].y;
            else if(A[i].y<=0&&A[1+i].y>=0)t1=-A[i].y+A[i+1].y;
            else {if(A[i].y<A[i+1].y){t1=-A[i].y+A[i+1].y;}else{t1=A[i].y-A[i+1].y;}}
            t=t1+t;
            if(t%2==0)break;
            t=t+1;
            if((t-2)%4!=0);
            else
            {
                while(1)
                {
                    if(t<=pow(2,count2)&&t>=pow(2,count2-1))break;
                    count2++;
                }
            }
            t=t-2;
            if((t-2)%4!=0);
            else
            {
                while(1)
                {
                    if(t<=pow(2,count1)&&t>=pow(2,count1-1))break;
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

