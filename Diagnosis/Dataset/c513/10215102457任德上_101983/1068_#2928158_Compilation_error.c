#include<stdio.h>
int find(int n,int m,int now){
    if(now>m)return (now-m+1)*(n-now)+find(m,now-1);
    else return 1;
    
}
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        if(n==-1||m==-1){
            break;
        }
        int sum;
        sum=find(n,m,n);
        printf("%d\n",sum);
    }
    return 0;
}