#include<stdio.h>
#include<stdlib.h>
#define C 101
typedef struct{int a;int b;} Order;
int cmp(const void* a,const void* b)
{
    Order p1=*(Order*)a,p2=*(Order*)b;
    return p1.a-p2.a;
}
int main()
{
    int T,i,j,n;scanf("%d",&T);
    for(int cas=0;cas<T;++cas)
    {
        scanf("%d",&n);Order arr[C];int flag=1;
        for(i=0;i<n;++i)scanf("%d %d",&arr[i].a,&arr[i].b);
        for(i=0;i<n;++i)
        {
            for(j=0;j<n;++j)if(arr[j].b==arr[i].a&&arr[i].a!=arr[i].b){flag=0;break;}
            if(!flag)break;
        }
        qsort(arr,n,sizeof(arr[0]),cmp);
        for(i=0;i<n-1;++i)if(arr[i].a==arr[i+1].a&&arr[i].b!=arr[i+1].b){flag=0;break;}
        if(flag)printf("Lucky dxw!\n");
        else printf("Poor dxw!\n");
    }
    return 0;
}