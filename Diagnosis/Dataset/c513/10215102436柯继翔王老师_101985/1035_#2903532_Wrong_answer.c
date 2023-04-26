#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b){
    int *a1 = (int*)a,*b1 = (int*)b;
    return b1[2] - a1[2];
}

int main()
{
    int m,n,a[1000][3];
    scanf("%d%d",&m,&n);
    for(int i = 0;i < m;i++){
        scanf("%d%d",&a[i][0],&a[i][1]);
        a[i][2] = a[i][0] * a[i][1];
    }
    qsort(a,m,sizeof(a[0]),cmp);
    int x = 0,y = 0;
    for(int i = 0;i < n;i++){
        x += 2 * a[i][0] * a[i][1];
        if(a[i][0] > y)y = a[i][0];
    }
    x += y * y;
    printf("%d",x);
    return 0;
}
