#include <stdio.h>
#include <stdlib.h>
#define p 1000000007
int main(){
    char s[1100];
    gets(s);
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
    printf("%d",sum);
    return 0;
}