#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b){
    return *(int*)a>*(int*)b?1:-1;
}
int main(){
    int t;
    scanf("%d",&t);getchar();
    while(t--){
        int former[101]={0},later[101]={0};
        int n;
        scanf("%d",&n);getchar();
        int a[101],b[101];
        for(int i=0;i<n;i++){
            scanf("%d%d",&a[i],&b[i]);
            former[a[i]]=1;later[b[i]]=1;
        }
        qsort(a,n,sizeof(a[0]),cmp);
        qsort(b,n,sizeof(b[0]),cmp);
        int flag=0;
        for(int i=1;i<101;i++){
            if(former[i]&&later[i]){flag=1;break;}
        }
        for(int i=1;i<n;i++){
            if(a[i]==a[i-1]&&b[i]!=b[i-1]){flag=1;break;}
        }
        if(flag)printf("Poor dxw!\n");
        else printf("Lucky dxw!\n");
    }
}
