#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int a[1001];
int cmp(const void*a1,const void*b1){
    int a2=a[*(int*)a1],b2=a[*(int*)b1];
    if (a2<b2) return 1;
    else if (a2>b2) return -1;
    else if(*(int*)a1<*(int*)b1) return -1;
    else return 1;
}


int main()
{
    int n;
    scanf("%d",&n);

    memset(a,-1,sizeof(a));
    for (int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        a[x]=n-i;
    }
    int m;
    scanf("%d",&m);
    int b[500];
    for(int i=0;i<m;i++){
        scanf("%d",&b[i]);
    }
    qsort(b,m,sizeof(b[0]),cmp);
    for (int i=0;i<m;i++)
    if (i!=m-1)
        printf("%d ",b[i]);
    else printf("%d\n",b[i]);
    return 0;
}