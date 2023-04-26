#include<stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    int n[74];
    n[0]=0;
    n[1]=1;
    n[2]=1;
    for(int i=0;i<t;i++){
        int m;
        scanf("%d",&m);
        if(m<3)printf("case #%d:\n%d",i,n[m]);
        else{
            for(int i=3;i<=m;i++)n[i]=n[i-1]+n[i-2]+n[i-3];
            printf("case #%d:\n%d",i,n[m]);
        }
    }
    return 0;
}