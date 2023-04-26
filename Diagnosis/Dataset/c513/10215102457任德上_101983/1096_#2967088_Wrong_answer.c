#include<stdio.h>
typedef struct{
    int a,b;
}cmd;
int main(){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int n,q[101]={0},flag=0,a,b;
        scanf("%d",&n);
        for(int k=0;k<n;k++){
            scanf("%d %d",&a,&b);
            if(q[a]==0)q[a]=1;
            else flag=-1;
            if(q[b]==0)q[b]=1;
            else flag=-1;
        }
        if(flag==-1)printf("Poor dxw!\n");
        else printf("Lucky dxw!\n");

    }
    return 0;
}
