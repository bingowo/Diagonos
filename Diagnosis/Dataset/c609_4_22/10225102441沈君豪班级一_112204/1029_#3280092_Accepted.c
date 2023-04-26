#include <stdio.h>
#include <stdlib.h>

int a[600];                   //便于cmp里面调用

int cmp(const void*A,const void*B)
{
    int M=*(int*)A;
    int N=*(int*)B;
    int x=0,y=0;          // 这里的局部x,y是为了确定位置
    while(a[x]!=M){
        if(a[x]==-1){
            break;
        }
        x++;
    }
    while(a[y]!=N){
        if(a[y]==-1){
            break;
        }
        y++;
    }
    if(x!=y){
        return x-y;
    }else{
        return M-N;
    }
}

int main()
{
    int x,y;
    scanf("%d",&x);
    int i;
    for(i=0;i<x;i++){
        scanf("%d",&a[i]);
    }
    i++;
    a[i]=-1;
    scanf("%d",&y);
    int b[y];
    for(int j=0;j<y;j++){
        scanf("%d",&b[j]);
    }
    qsort(b,y,sizeof(int),cmp);
    for(int j=0;j<y;j++){
        printf("%d ",b[j]);
    }
    return 0;
}
