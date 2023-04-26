#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct node
{
    int x,y;
    int l;
}NODE;
int cmp(const void *a,const void *b)
{
    NODE s1=*(NODE*)a;
    NODE s2=*(NODE*)b;
    if(s1.l!=s2.l)
        return s2.l-s1.l;
    else if(s1.x!=s2.x)
        return s1.x-s2.x;
    else
        return s1.y-s2.y;
}
int main()
{
    int n;
    scanf("%d",&n);
    NODE a[n];
    //int b[100]={1,3,7,15,31,}
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&a[i].x,&a[i].y);
        a[i].l=abs(a[i].x)+abs(a[i].y);
    }
    qsort(a,n,sizeof(a[0]),cmp);
    int len=0,ans=0,temp=0;
    len=abs(a[0].y-a[1].y)+abs(a[0].x-a[1].x);
    for(int i=0;i<n-1;i++)
    {
        temp=abs(a[i].y-a[i+1].y)+abs(a[i].x-a[i+1].x);
        if(temp%2==0)
        {
            ans=0;
            break;
        }
        for(int j=0;j<64;j++)
        {
            if(temp<=(pow(2,j+1)-1))
            {
                ans=ans+j+1;
              // printf("%d\n",j+1);
                break;
            }
        }
    }
    printf("%d\n%d",len,ans);
    return 0;
}
