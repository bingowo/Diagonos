#include <stdio.h>
#include <stdlib.h>

typedef struct{int** a[15];int mark;}student;
int cmp(const void* a,const void *b)
{
    int* aa=(int*)a;
    int* bb=(int*)b;
    for(int i=0;i<50;i++){
        if(aa[i]==bb[i])continue;
        else return bb[i]-aa[i];
    }

}
int main()
{
    int n,t;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&t);
        int *str[t];
        for(int i=0;i<t;i++){
            str[i]=(int *)malloc(sizeof(int)*50);
            for(int j=0;j<50;j++){
            scanf("%d",str[i]+j);
            if(str[i][j]==-1)break;
            }

        }
        qsort(str,t,sizeof(str[0]),cmp);
        for(int i=0;i<t;i++){
            for(int j=0;j<50;j++){
            if(str[i][j]==-1)break;
            printf("%d ",str[i][j]);
            }
            printf("\n");
            free(str[i]);
        }
    }
    return 0;
}
