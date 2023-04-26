#include<stdio.h>
#include<stdlib.h>

int cmp(const void* a, const void* b)
{
    long long *a0=(long long*)a,*b0=(long long*)b;
    if(a0[2]==b0[2]) return b0[0]>a0[0] ? 1:-1;
    else return b0[2]>a0[2] ? 1:-1;
}

int main()
{
    int i,n,m;
    scanf("%d %d",&n,&m);
    long long circle[1010][3]={0};
    for(i=0;i<n;i++)
    {
        scanf("%lld %lld",&circle[i][0],&circle[i][1]);
        circle[i][2]=2*circle[i][0]*circle[i][1];
    }
    qsort(circle,n,sizeof(circle[0]),cmp);
    
    long long max=-1;
    for(i=0;i<n;i++)
    {
        long long sum=circle[i][0]*circle[i][0]+circle[i][2];
        int j,cnt;
        for(cnt=1,j=0;cnt<m && j<n;j++)
        {
            if(circle[j][0]<=circle[i][0] && j!=i)
            {
                cnt++;
                sum+=circle[j][2];
            }
        }
        if(sum>max) max=sum;
    }
    printf("%lld",max);
    return 0;
}