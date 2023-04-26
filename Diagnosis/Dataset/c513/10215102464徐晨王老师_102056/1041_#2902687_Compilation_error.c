#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char s[51];
    gets(s);
    int x=sum;
    for(int i=0;i<strlen(s);i++){
        int sum=1;
        for(int j=i;j<strlen(s);j++){
            if(s[j]!=s[j+1]){
                sum=sum+1;
            }
            if(sum>x)x=sum;
        }
    }
    printf("%d",x);
}