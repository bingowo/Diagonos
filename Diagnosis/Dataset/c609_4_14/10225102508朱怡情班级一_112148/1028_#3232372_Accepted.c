#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int cmp(const void* a,const void* b)
{
    int *x=*(int(*)[51])a;
    int *y=*(int(*)[51])b;
    for(int i=0;i<50;i++){
        if(x[i]==y[i])continue;
        else return y[i]-x[i];
    }
    return y[50]-x[50];
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int a[1001][51];
        for(int i=0;i<n;i++){
            for(int j=0;;j++){
                int temp;
                scanf("%d",&temp);
                a[i][j]=temp;
                if(temp==-1)break;
            }
        }
        qsort(a,n,sizeof(a[0]),cmp);
        for(int i=0;i<n;i++){
            for(int j=0;a[i][j]!=-1;j++){
                printf("%d ",a[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
