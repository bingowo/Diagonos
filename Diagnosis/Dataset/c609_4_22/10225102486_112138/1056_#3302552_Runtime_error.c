#include<stdio.h>

int combine(int x){
    int ans=1;
    for(int i=1;i<=x;i++)
        ans*=i;
    return ans;
}

int main(){
    int T,m,n;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        scanf("%d%d",&m,&n);
        printf("case #%d:\n%d\n",t,combine(m)/(combine(m-n)*combine(n)));
    }
    return 0;
}

