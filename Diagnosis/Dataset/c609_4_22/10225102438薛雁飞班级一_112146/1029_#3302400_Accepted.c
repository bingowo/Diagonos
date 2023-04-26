#include <stdio.h>
#include <stdlib.h>
int a[1001]={-1};
int cmp(const void* p1,const void* p2)
{
    int x,y;
    x=*((int*)p1);y=*((int*)p2);
    if((a[x]==-1)&&(a[y]==-1)){
        if(x>y)return 1;
        else return -1;
    }
    else if((a[x]==-1)&&(a[y]>=0))return 1;
    else if((a[y]==-1)&&(a[x]>=0))return -1;
    else{
        if(a[x]>a[y])return 1;
        else return -1;
    }
}
int main()
{
    int m,n;
    scanf("%d",&m);
    for(int i=0;i<1001;i++)a[i]=-1;
    for(int i=0;i<m;i++){
        int x;
        scanf("%d",&x);
        a[x]=i;
    }
    scanf("%d",&n);
    int b[501];
    for(int i=0;i<n;i++){
        scanf("%d",&b[i]);
    }
    qsort(b,n,sizeof(b[0]),cmp);
    for(int i=0;i<n;i++)printf("%d ",b[i]);
    return 0;
}
