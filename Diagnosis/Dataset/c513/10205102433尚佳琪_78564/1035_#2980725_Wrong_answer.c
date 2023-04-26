#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int r;
    int h;
    int d;
    int c;
    int s;
}NODE;
int cmp(const void*a,const void*b)
{
    NODE s1=*(NODE*)a;
    NODE s2=*(NODE*)b;
    if(s1.r!=s2.r)
        return s2.r-s1.r;
    else
        return s2.c-s1.c;
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    NODE a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&a[i].r,&a[i].h);
        a[i].d=a[i].r*a[i].r;
        a[i].c=2*a[i].r*a[i].h;
        a[i].s=a[i].c+a[i].d;
       // printf("%d\n",a[i].s);
    }
    qsort(a,n,sizeof(a[0]),cmp);
    int temp=1,sum=0,res=0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i].s;
        temp=1;
      //  printf("%d\n",sum);
       for(int j=i+1;j<n&&temp<m;j++)
       {
           sum+=a[j].c;
           temp++;
       }
       res=sum>res?sum:res;
      //  printf("%d\n",sum);
       sum=0;
    }
    printf("%d",res);
    return 0;
}
