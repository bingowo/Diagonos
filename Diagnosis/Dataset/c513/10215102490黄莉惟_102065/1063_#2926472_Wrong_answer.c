#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int GCD(int x,int y){
    int sum=0;
    while(x!=0||y!=0){
        if(x>y){
            x-=y;
            sum=sum+y*y;
        }else if(x<y){
            y-=x;
            sum+=x*x;
        }else{
            sum+=x*x;
            x-=x;
            y-=y;
            
        }
    }
    return sum;
}
int main(){
    int x,y;
    scanf("%d %d",&x,&y);
    printf("%d",GCD(x,y));
}