#include <stdio.h>
#include <stdlib.h>

int a[100000];
int num=0;

void f(int* p,int k,int w,int n)
{
    if(k==n-1){
        a[num++]=w+p[k];
        a[num++]=w-p[k];
        a[num++]=w;
        return;
    }
    else{
        f(p,k+1,w+p[k],n);
        f(p,k+1,w-p[k],n);
        f(p,k+1,w,n);
    }
}

int main()
{
    int n=0,all=0;
    scanf("%d",&n);
    int* p=(int* )malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",&p[i]);
        all+=p[i];
    }
    int w=0,k=0;
    int* ans=(int* )malloc(all*sizeof(int));
    for(int i=0;i<all;i++) ans[i]=0;
    f(p,k,w,n);
    for(int j=0;j<num;j++){
        if(a[j]>0){
            ans[a[j]-1]=1;
        }
    }
    for(int jj=0;jj<all;jj++) printf("%d",ans[jj]);
    printf("\n");
    free(p);
    free(ans);
    return 0;
}
