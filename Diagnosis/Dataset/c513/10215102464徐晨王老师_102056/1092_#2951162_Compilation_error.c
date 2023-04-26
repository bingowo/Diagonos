#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void multi(int* list,int ans){
    for(int i=0;list[i]!=-1;i++){
        list[i+1]=list[i]*ans/10+list[i+1]*ans;
        list[i]=list[i]*ans%10;
    }
}

int main(){
    char s[1000];
    scanf("%s",s);
    int len=strlen(s);
    int sum[1000];
    sum[0]=1;
    for(int i=1;i<1000;i++){
        sum[i]=-1;
    }
    for(int i=0;i<len;i++){
        if(len==1)break;
        if(i==0){
            if(s[i]!=s[i+1])multi(sum,2);
            else sum=sum;
        }
        else if(i==len-1){
            if(s[i]!=s[i-1])multi(sum,2);
            else sum=sum;
        }
        else{
            if(s[i-1]==s[i]&&s[i+1]==s[i])sum=sum;
            else{
                if((s[i-1]-s[i])*(s[i+1]-s[i])==0)multi(sum,2);
                else multi(sum,3);
            }
        }
    }
    for(int i=0;sum[i]!=-1;i++){
        printf("%d",sum[i]);
    }
    return 0;
}