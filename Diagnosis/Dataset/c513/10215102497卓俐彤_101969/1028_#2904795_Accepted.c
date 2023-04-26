#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    char ad;
    scanf("%c",&ad);
    int num[1000];
    for(int i=0;i<1000;i++)num[i]=1;
    int x;
    while(scanf("%d",&x)!=EOF){
        if(num[x-1]==1)num[x-1]=0;
        else continue;
    }
    int res[1000];
    int k=0;
    for(int i=0;i<1000;i++){
        if(!num[i])res[k++]=i+1;
    }
    if(ad=='A'){
        for(int i=0;i<k-1;i++)printf("%d ",res[i]);
        printf("%d\n",res[k-1]);
    }
    else if(ad=='D'){
        for(int i=k-1;i>0;i--)printf("%d ",res[i]);
        printf("%d\n",res[0]);
    }
    return 0;
}
