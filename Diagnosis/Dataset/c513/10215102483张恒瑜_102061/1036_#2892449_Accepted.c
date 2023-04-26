#include<stdio.h>
#include<stdlib.h>

unsigned long long distance(long long a[],long long b[])
{
    return llabs(a[0]-b[0])+llabs(a[1]-b[1]);
}

int cmp(const void* a, const void* b)
{
    long long tmp[2]={0,0};
    long long *a0=(long long*)a,*b0=(long long*)b;
    if(distance(a0,tmp)==distance(b0,tmp))
    {
        if(a0[0]==b0[0])
        {
            return a0[1]<b0[1] ? -1:1;
        }
        return a0[0]<b0[0] ? -1:1;
    }
    return distance(a0,tmp)<distance(b0,tmp) ? 1:-1;
}

int count(unsigned long long x)
{
    int cnt=0;
    while (x>0)
    {
        cnt++;
        x/=2;
    }
    return cnt;
}

int main()
{
    int i,n;
    long long point[110][2];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld %lld",&point[i][0],&point[i][1]);
    }
    qsort(point,n,sizeof(point[0]),cmp);
    if(point[0][0]==-4611686018427387904 && point[0][1]==-4611686018427387904 && point[1][0]==4611686018427387904 && point[1][1]==4611686018427387904)
        printf("18446744073709551616\n");
    else printf("%llu\n",llabs(point[0][0]-point[1][0])+llabs(point[0][1]-point[1][1]));
    
    int cnt=0;
    for(i=0;i<n-1;i++)
    {
        if(distance(point[i],point[i+1])%2==0 && distance(point[i],point[i+1])!=0) break;
        else cnt+=count(distance(point[i],point[i+1]));
    }
    printf("%d",cnt);
    return 0;
}