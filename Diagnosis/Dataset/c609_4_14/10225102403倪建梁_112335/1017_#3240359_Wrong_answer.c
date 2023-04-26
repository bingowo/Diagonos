#include<stdio.h>
int main()
{
    int a[1001]={0},i,t,count=0;char c;
    scanf("%c",&c);
    for(i=0;i<100;i++){
        scanf("d",t);
        if(a[t]==0){
            a[t]=t;
            count++;
        }
    }
    if (c=='A'){
        for(i=0;i<1001;i++){
            if(a[i]!=0) printf("%d ",a[i]);
        }
    }
    else{
        for(i=1000;1>=0;i--){
            if(a[i]!=0) printf("%d ",a[i]);
        }
    }
}