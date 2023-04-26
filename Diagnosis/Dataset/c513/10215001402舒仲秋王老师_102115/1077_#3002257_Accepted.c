#include <stdio.h>
#include <stdlib.h>
int base[1001];
struct data
{
    int x;
    int y;
};

int cmp(const void *a,const void *b)
{
    struct data d1,d2;
    d1=*((struct data*)a),d2=*((struct data*)b);
    int t;
    if(base[d1.x]<base[d2.x]) t=-1;
    else if(base[d1.x]>base[d2.x]) t=1;
    else
    {
        if(base[d1.x]==1000) t=d1.x-d2.x;
        else t=1;
    }
    return t;
}

int main()
{
    for(int i=0;i<1001;i++) base[i]=1000;
    int n1,n2,i;
    scanf("%d",&n1);
    for(i=0;i<n1;i++)
    {
        int mid;
        scanf("%d",&mid);
        base[mid]=i+1;
    }
    scanf("%d",&n2);
    struct data b[1001];
    for(i=0;i<n2;i++)
    {
        scanf("%d",&b[i].x);
        b[i].y=i;
    }
    qsort(b,n2,sizeof(b[0]),cmp);
    for(i=0;i<n2-1;i++)
        printf("%d ",b[i].x);
    printf("%d",b[i].x);
    return 0;
}
