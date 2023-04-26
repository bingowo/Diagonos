#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int f[1234];
int n;
int a[1234][1234];

int cmp(const void *st1,const void *st2){
    int *x=(int**)st1;
    int *y=(int**)st2;
    int i=0;
    while (1){
        if (x[i]==-1) return 1;
        if (y[i]==-1) return -1;
        if (x[i]==y[i]) {
            i++;
            continue;
        }
        else return y[i]-x[i];
    }
}

int main(){
    int t;
    scanf("%d",&t);
    for (int l=1;l<=t;l++){
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            int j=0;
            while (x!=-1){
                a[i][j]=x;
                j++;
                scanf("%d",&x);
            }
            a[i][j]=-1;
        }
        qsort(a+1,n,sizeof(a[1]),cmp);
        for (int i=1;i<=n;i++){
            int j;
            for (j=0;a[i][j+1]!=-1;j++){
                printf("%d ",a[i][j]);
            }
            printf("%d\n",a[i][j]);
        }
    }
    return 0;
}
