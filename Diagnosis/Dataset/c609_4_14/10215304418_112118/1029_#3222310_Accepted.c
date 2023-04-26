#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int f[1234];
int a[1234];
int cmp(const void *st1,const void *st2){
    int x=*(int*)st1;
    int y=*(int*)st2;
    if (f[x]==0 && f[y]==0){
        return x-y;
    }
    else if (f[x]==0) return 1;
    else if (f[y]==0) return -1;
    else return f[x]-f[y];
}

int main(){
    int n,m;
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        f[x]=i;
    }
    scanf("%d",&m);
    for (int i=1;i<=m;i++){
        scanf("%d",&a[i]);
    }
    qsort(a+1,m,sizeof(int),cmp);
    for (int i=1;i<=m;i++)
        printf("%d ",a[i]);
    return 0;
}
