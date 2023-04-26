#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int a,b;
}node;
int cmp(const void *a,const void *b){
    node x=*(node*)a,y=*(node*)b;
    return x.a>y.a?1:-1;
}
int main(){
    int t;
    scanf("%d",&t);getchar();
    while(t--){
        int former[101]={0},later[101]={0};
        int n;
        scanf("%d",&n);getchar();
        node *data=(node*)malloc(sizeof(node)*n);
        for(int i=0;i<n;i++){
            scanf("%d%d",&data[i].a,&data[i].b);
            former[data[i].a]=1;later[data[i].b]=1;
        }
        qsort(data,n,sizeof(data[0]),cmp);
        int flag=0;
        for(int i=1;i<101;i++){
            if(former[i]&&later[i]){flag=1;break;}
        }
        for(int i=1;i<n;i++){
            if(data[i].a==data[i-1].a&&data[i].b!=data[i-1].b){flag=1;break;}
        }
        if(flag)printf("Poor dxw!\n");
        else printf("Lucky dxw!\n");
    }
}
