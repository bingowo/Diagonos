#include <stdio.h>
#include <stdlib.h>
#define p 1000000007
int main(){
    char s[1100];
    gets(s);
    if(strlen(s)==1)printf("1");
    else{
    int sum;
    if(s[0]==s[1])sum=1;
    if(s[0]!=s[1])sum=2;
    for(int i=1;i<strlen(s)-1;i++){
        if(s[i]!=s[i-1]&&s[i]!=s[i+1]&&s[i-1]!=s[i+1]){
            sum=sum*3;
            sum=sum%p;
        }
        else if(s[i]==s[i-1]&&s[i]==s[i+1]&&s[i-1]==s[i+1]){
            sum=sum;
            sum=sum%p;
        }
        else{
            sum=sum*2;
            sum=sum%p;
        }
    }
    if(s[strlen(s)-1]==s[strlen(s)-2])sum=sum;
    if(s[strlen(s)-1]!=s[strlen(s)-2])sum=2*sum;
    sum=sum%p;
    printf("%d",sum);
    }

    return 0;
}