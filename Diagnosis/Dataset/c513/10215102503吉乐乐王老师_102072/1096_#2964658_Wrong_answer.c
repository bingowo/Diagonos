#include<stdio.h>
#include<stdlib.h>
int main(){
    int t;
    scanf("%d",&t);getchar();
    while(t--){
        int former[101]={0},later[101]={0};
        int n;
        scanf("%d",&n);getchar();
        int a,b;
        for(int i=0;i<n;i++){
            scanf("%d%d",&a,&b);
            former[a]++;later[b]++;
        }
        int flag=0;
        for(int i=1;i<101;i++){
            if(former[i]&&later[i]){flag=1;break;}
        }
        if(flag)printf("Poor dxw!\n");
        else printf("Lucky dxw!\n");
    }
}
