#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int f;
    int l;
}node;
int main(){
    int t;
    scanf("%d",&t);getchar();
    while(t--){
        int later[101]={0};
        int n;
        scanf("%d",&n);getchar();
        node *data=(node*)malloc(sizeof(node)*n);
        for(int i=0;i<n;i++){
            scanf("%d%d",&data[i].f,&data[i].l);
            later[data[i].l]=1;
        }
        int flag=0;
        for(int i=1;i<n;i++){
            if(later[data[i].f]&&later[data[i].l]){flag=1;break;}
        }
        if(flag)printf("Poor dxw!\n");
        else printf("Lucky dxw!\n");
    }
}
