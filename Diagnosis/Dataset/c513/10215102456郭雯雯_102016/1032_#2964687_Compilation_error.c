#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int num[50],l;
}step;

int main(){
    int t;
    scanf("%d",&t);//问题数
    while(t--){
        int n;
        scanf("%d",&n);//数据数
        step rop[n];
        for(int i=0;i<n;i++){
            int s,c=0;scanf("%d",&s);
            rop[i].num[50]={0};rop[i].l=0;
            while(s!=-1){
                rop[i].num[c]=s;c++;rop[i].l++;
            }
            printf("%d",rop[i].l);
            continue;
        }
    }
    return 0;
}