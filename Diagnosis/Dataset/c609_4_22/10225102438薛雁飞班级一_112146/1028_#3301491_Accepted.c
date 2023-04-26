#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a,const void *b)
{
    int *p1,*p2;
    p1=(int*)a;p2=(int*)b;
    int i=0;
    while((*(p1+i)!=-1)&&(*(p2+i)!=-1)){
        if((*(p1+i))>(*(p2+i)))return -1;
        else if((*(p1+i))<(*(p2+i)))return 1;
        else i++;
    }
    if((*(p1+i))==-1)return 1;
    else return -1;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int k=0;k<t;k++){
        int n;
        scanf("%d",&n);
        getchar();
        int c[1000][51];
        for(int i=0;i<n;i++){
            int j=0;
            while(scanf("%d",&c[i][j])&&c[i][j]!=-1){
                j++;
            }
        }
        qsort(c,n,sizeof(c[0]),cmp);
        for(int i=0;i<n;i++){
            int j=0;
            while(c[i][j]!=-1){
                printf("%d ",c[i][j]);
                j++;
            }
            printf("\n");
        }
    }

    return 0;
}
