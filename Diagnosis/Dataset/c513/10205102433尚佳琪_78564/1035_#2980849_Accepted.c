#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
   long long r,h,c;
}NODE;
int cmp(const void*a,const void*b)
{
    NODE s1=*(NODE*)a;
    NODE s2=*(NODE*)b;
    if(s2.c>s1.c)
        return 1;
    else return -1;//数据范围过大，使用>/<而不用—
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    NODE a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%lld %lld",&a[i].r,&a[i].h);
        a[i].c=2*a[i].r*a[i].h;
    }
    qsort(a,n,sizeof(a[0]),cmp);
    int temp=1;
    long long sum=0,res=0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i].c+a[i].r*a[i].r;
        temp=1;
       // printf("%llu\n",sum);
       for(int j=0;j<n&&temp<m;j++)
       /*将a[i]作为最下面的那个，
       只找比a[i].r小的作为上面的，因此应该按侧面积排序，
        这样找到的就是以a[i].r为底侧面积最大的*/
       {
           if(i==j||a[i].r<a[j].r)
                continue;
           sum+=a[j].c;
           temp++;
       }
       if(temp==m)
            res=sum>res?sum:res;
      //  printf("%llu\n",sum);
       sum=0;
    }
    printf("%llu",res);
    return 0;
}
