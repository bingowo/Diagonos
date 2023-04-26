#include<stdio.h>
typedef struct{
    int l,r;
}cmd;
int main(){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int n,flag=0,a,b;
        cmd q[101]={0,0};
        scanf("%d",&n);
        for(int k=0;k<n;k++){
            scanf("%d %d",&a,&b);
            q[a].l++;
            q[b].r++;
            if((q[a].l==2)&&(q[b].r==2)){q[a].l=1,q[b].r=1;}
            if(((q[a].l>0)&&(q[a].r+q[a].l>=2))||(q[a].l>=2))flag=-1;
            else if(((q[b].l>0)&&(q[b].r+q[b].l>=2))||(q[b].l>=2))flag=-1;
        }
        if(flag==-1)printf("Poor dxw!\n");
        else printf("Lucky dxw!\n");

    }
    return 0;
}
