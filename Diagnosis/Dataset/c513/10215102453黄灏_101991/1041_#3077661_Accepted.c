#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
    char s[51];
    scanf("%s",s);
    int len;
    len=strlen(s);
    int temp=1,max=1;
    for(int i=1;i<len;i++){
        if(s[i]!=s[i-1]){
            temp++;
            if(temp>max) max=temp;
        }
        else temp=1;
    }
    printf("%d",max);
    return 0;
}
