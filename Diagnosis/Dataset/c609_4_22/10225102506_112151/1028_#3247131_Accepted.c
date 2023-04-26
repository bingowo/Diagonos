#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b){
    int *p1=(int *)a;
    int *p2=(int *)b;
    while(*p1!=-1 && *p2!=-1 && *p1==*p2)   p1++,p2++;
    return *p2-*p1;
}

int main()
{
    int I,T;
    for(scanf("%d",&T),I=0;I<T;I++){
        int a[1000][51],i,j=0,n;
        scanf("%d",&n);
        for(i=0;i<n;i++,j=0){
            do scanf("%d",&a[i][j++]);
            while(a[i][j-1]!=-1);
        }
        qsort(a,n,sizeof(a[0]),cmp);
        for(i=0;i<n;i++){
            j=0;
            while(a[i][j]!=-1)
                printf(j==0?"":" "),printf("%d",a[i][j++]);
            printf("\n");
        }
    }
    return 0;
}
