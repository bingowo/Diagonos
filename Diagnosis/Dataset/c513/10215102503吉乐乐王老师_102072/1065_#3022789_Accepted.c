#include<stdio.h>
#define N 30
typedef struct{
    int a,b;
}node;
int main(){
    node up[N];
    node down[N];
    int A,n,m,x;
    scanf("%d%d%d%d",&A,&n,&m,&x);
    up[1].a=1,up[1].b=0;
    down[1].a=0,down[1].b=0;
    up[2].a=0,up[2].b=1;
    down[2].a=0,down[2].b=1;
    int aa=1,bb=0;
    for(int i=3;i<n;i++){
        up[i].a=up[i-1].a+up[i-2].a;
        up[i].b=up[i-1].b+up[i-2].b;
        down[i].a=up[i-1].a;down[i].b=up[i-1].b;
        aa+=up[i].a-down[i].a;
        bb+=up[i].b-down[i].b;
    }
    int B=(m-aa*A)/bb;
    up[1].a=A,up[1].b=0;
    down[1].a=0,down[1].b=0;
    up[2].a=0,up[2].b=B;
    down[2].a=0,down[2].b=B;
    int ret[N];
    ret[1]=ret[2]=A;
    for(int i=3;i<n;i++){
        up[i].a=up[i-1].a+up[i-2].a;
        up[i].b=up[i-1].b+up[i-2].b;
        down[i].a=up[i-1].a;down[i].b=up[i-1].b;
        ret[i]=ret[i-1]+up[i].a+up[i].b-down[i].a-down[i].b;
    }
    ret[n]=m;
    printf("%d\n",ret[x]);
}