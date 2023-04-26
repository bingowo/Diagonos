#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void reverse(char* s)
{
    int i,j;
    char tmp;
    for (i=0,j=strlen(s)-1;i<j;i++,j--)
    {
        tmp=s[i];
        s[i]=s[j];
        s[j]=tmp;
    }
}

unsigned long long aabs(long long a)
{
    unsigned long long n;
    n=(a>0)?a:-a;
    return n;

}

int steps(long long a,long long b)
{
    long long n=1,i=0,j,k,h;
    unsigned long long a1,b1;
    a1=(unsigned long long)(a>0)?a:-a;
    b1=(unsigned long long)(b>0)?b:-b;
    unsigned long long m=a1+b1,m1=m;
    while (m1)
    {
        m1=m1/2;
        i++;
    }
    if (m==0) return 0;
    if (m%2==1) return i;
    else return -1;

}


typedef struct
{
    long long x;
    long long y;
    unsigned long long distance;
}POINT;

int cmp(const void* a,const void* b)
{
    POINT* pa=(POINT*)a; POINT* pb=(POINT*)b;
    if (pa->distance>pb->distance) return -1;
    if (pa->distance<pb->distance) return 1;
    if (pa->distance==pb->distance)
    {
        if (pa->x>pb->x) return 1;
        if (pa->x<pb->x) return -1;
        if (pa->x==pb->x)
        {
            return (pa->y>pb->y)?1:-1;
        }
    }

}

int main()
{
    int n,i;
    scanf("%d",&n);
    POINT* arr=(POINT*)malloc(n*sizeof(POINT));
    for(i=0;i<n;i++)
    {
        scanf("%lld %lld",&arr[i].x,&arr[i].y);
        arr[i].distance=aabs(arr[i].x)+aabs(arr[i].y);
    }
    qsort(arr,n,sizeof(POINT),cmp);
    int w,z;
    long long ss=0;
    for(i=0;i<n-1;i++)
    {
        w=steps(arr[i+1].x-arr[i].x,arr[i+1].y-arr[i].y);
        if (w!=-1)
            ss+=w;
        else break;
    }
    if (aabs(arr[1].x-arr[0].x)==4611686018427387904*2 && aabs(arr[1].y-arr[0].y)==4611686018427387904*2)
    {
        char s[30]={0};
        i=0;
        unsigned long long nm=ULLONG_MAX;
        while (nm)
        {
            s[i++]=nm%10+'0';
            nm=nm/10;
        }
        s[0]=s[0]+1;
        reverse(s);
        printf("%s\n",s);
    }
    else
    {
        unsigned long long dist=aabs(arr[1].x-arr[0].x)+aabs(arr[1].y-arr[0].y);
        printf("%llu\n",dist);
    }
    printf("%lld\n",ss);
    return 0;
}