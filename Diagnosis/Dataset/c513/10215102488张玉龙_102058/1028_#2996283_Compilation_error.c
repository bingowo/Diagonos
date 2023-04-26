#include<stdio.h>
#include<stdlib.h>
int main()
{
    char sort;
    int num[1001];
    int i=0;
    for(i=0;i<=1000;i++)
        num[i]=0;
    scanf("%c",&sort)
    while(scanf("%d",&i)!=EOF){
        num[i]++;
    }
    if(sort=='A'){
        for(i=0;i<=1000;i++){
            if(num[i]!=0)
            printf("%d ",i);
        }
    }
    else{
        for(i=1000;i>=0;i--){
            if(num[i]!=0)
            printf("%d ",i);
        }
    }
    
}