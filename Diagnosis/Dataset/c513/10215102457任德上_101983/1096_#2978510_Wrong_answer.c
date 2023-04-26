#include<stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int times,flag=0,a1=0,b1=0;
        int r[101]={0},l[101]={0};
        scanf("%d",&times);
        for(int k=0;k<times;k++){
            int a,b;
            scanf("%d%d",&a,&b);
            if(a==a1&&b==b1);
            else if(a!=b&&l[a]!=r[b]){
                l[a]++;
                r[b]++;
                if(l[a]>=2)flag=-1;
                if(l[a]>=1&&r[a]>=1)flag=-1;
                if(l[b]>=1&&r[b]>=1)flag=-1;
                a1=a;
                b1=b;
            }
            else{
                a1=a;
                b1=b;
            }
        }
        if(flag==-1)printf("Poor dxw!\n");
        else printf("Lucky dxw!\n");
    }
    return 0;
}