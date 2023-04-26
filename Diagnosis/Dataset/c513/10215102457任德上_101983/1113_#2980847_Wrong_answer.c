#include<stdio.h>
int main(){
    int k,m,num[200]={0};
    for(int i=0;i<200;i++)num[i]=0;
    scanf("%d%d",&k,&m);
    num[22]=1;
    m=m+20;
    for(int i=23;i<=m;i++){
        for(int p=i-k;p<i;p++){
            num[i]+=num[p];
        }
    }
    printf("%d",num[m]);
    return 0;
}