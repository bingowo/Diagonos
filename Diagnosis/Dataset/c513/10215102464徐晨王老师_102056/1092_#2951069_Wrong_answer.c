#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    char s[1000];
    scanf("%s",s);
    int len=strlen(s);
    long long int sum=1;
    for(int i=0;i<len;i++){
        if(len==1)break;
        if(i==0){
            if(s[i]!=s[i+1])sum=sum*2;
            else sum=sum;
        }
        else if(i==len-1){
            if(s[i]!=s[i-1])sum=sum*2;
            else sum=sum;
        }
        else{
            if(s[i-1]==s[i]&&s[i+1]==s[i])sum=sum;
            else{
                if((s[i-1]-s[i])*(s[i+1]-s[i])==0)sum=sum*2;
                else sum=sum*3;
            }
        }
    }
    printf("%lld",sum);
    return 0;
}