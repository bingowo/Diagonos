#include<stdio.h>
int main()
{
    int a[1001]={0},i,t;char c;
    scanf("%c",&c);
    while(scanf("%d",&t) != EOF){
        if(a[t]==0){
            a[t]=t;
        }
    }
    if (c=='A'){
        for(i=0;i<1001;i++){
            if(a[i]!=0) printf("%d ",a[i]);
        }
    }
    else{
        for(i=1000;i>=0;i--){
            if(a[i]!=0) printf("%d ",a[i]);
        }
    }
    return 0;
}