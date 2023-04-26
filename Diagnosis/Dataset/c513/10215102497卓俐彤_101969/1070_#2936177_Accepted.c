#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int feb(int n){
    if(n==0)return 1;
    if(n==1)return 2;
    if(n==2)return 4;
    return feb(n-1)*2-feb(n-2)+feb(n-3);
}

int main(){
    int nums[20];
    for(int i=0;i<20;i++)nums[i]=feb(i+1);
    int n=0;
    while(scanf("%d",&n)&&n!=-1)printf("%d\n",nums[n-1]);
}
