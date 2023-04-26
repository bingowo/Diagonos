#include<stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int n,q[101]={0},flag=0,a,b,p[101]={0};
        scanf("%d",&n);
        for(int k=0;k<n;k++){
            scanf("%d %d",&a,&b);
            if(q[a]==0)q[a]=1;
            else flag=-1;
            if(q[b]==0)q[b]=-1;
            else if(q[b]==1)flag=-1;
        }
        if(flag==-1)printf("Poor dxw!\n");
        else printf("Lucky dxw!\n");

    }
    return 0;
}
