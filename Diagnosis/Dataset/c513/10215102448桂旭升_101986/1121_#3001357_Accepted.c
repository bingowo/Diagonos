#include<stdio.h>
void trans(int* a,int n,int item,int now,char *c,int sum){
    sum+=now*a[item];
    if(sum>=1)c[sum-1]='1';
    if(item==n-1)return;
    trans(a,n,item+1,0,c,sum);
    trans(a,n,item+1,1,c,sum);
    trans(a,n,item+1,-1,c,sum);
}
int main(){
    int n,a[100],sum=0;
    char c[1000];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    for(int i=0;i<sum;i++)c[i]='0';
    int item=0;
    trans(a,n,item,0,c,0);
    trans(a,n,item,1,c,0);
    trans(a,n,item,-1,c,0);
    c[sum]=0;
    printf("%s",c);
    return 0;
}
