#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char s[51];
    gets(s);
    int x=1;
    for(int i=0;i<strlen(s)-1;i++){
        if(s[i]!=s[i+1]){
        int sum=1;
        for(int j=i;j<strlen(s)-1;j++){
            if(s[j]!=s[j+1]){
                sum=sum+1;
            }
            else break;
        }
        if(sum>x)x=sum;
        }
    }
    printf("%d",x);
}