#include<stdio.h>
int main(){
    int k,m,num[200]={0};
    scanf("%d%d",&k,&m);
    num[12]=1;
    m=m+10;
    for(int i=13;i<=m;i++){
        for(int p=i-k;p<i;p++){
            num[i]+=num[p];
        }
    }
    printf("%d",num[m-10]);
    return 0;
}