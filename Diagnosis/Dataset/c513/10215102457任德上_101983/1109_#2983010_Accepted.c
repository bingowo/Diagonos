#include<stdio.h>
void input(int *n,int k,int sum){
    if(n[k]!=0){
        if(sum!=k){
            if(n[k]<0)printf("-");
            else printf("+");
        }
        else if(sum==k&&n[k]<0)printf("-");
        n[k]=n[k]>0?n[k]:-n[k];
        if(k==0)printf("%d",n[k]);
        else if(n[k]==1)printf("x");
        else if(n[k]>1)printf("%dx",n[k]);
        if(k>1)printf("^%d",k);
    }
}
int main(){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int n[9],sum=-1;
        for(int k=8;k>=0;k--){scanf("%d",&n[k]);if(n[k]!=0&&sum==-1)sum=k;}
        printf("case #%d:\n",i);
        for(int k=8;k>=0;k--)input(n,k,sum);
        if(sum==-1)printf("0");
        printf("\n");
    }
    return 0;
}
