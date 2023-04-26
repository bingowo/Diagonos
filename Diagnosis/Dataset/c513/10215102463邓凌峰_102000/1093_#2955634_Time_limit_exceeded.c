#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int judge(int *num){//是否被9整除
    int numAdd=0;
    for(int i=0;i<100;i++){
        numAdd+=num[i];
        if(num[i]==9) return 0;//判断有没有9
    }
    if(numAdd%9==0) return 0;
    return 1;
}

void addOne(int *num,int len){
    num[len-1]+=1;
    for(int i=len-1;i;i--){
        if(num[i]>9){
            num[i-1]+=num[i]/10;
            num[i]%=10;
        }
    }
}




int main()
{
   char snum[101];scanf("%s",&snum);
   int num[100]={0};
   for(int i=100-strlen(snum),j=0;i<100;i++,j++){
        num[i]=snum[j]-'0';
   }
   do{
        addOne(num,100);
   }while(!judge(num));
   int idx=0;
   for(;num[idx]==0;idx++);
   for(;idx<100;idx++){
        printf("%d",num[idx]);
   }


   return 0;

}



