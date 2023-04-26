#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
    char s[100];
    char b;
    int lens=0;
    while((b=getchar())!=EOF){
        s[lens]=b;
        lens++;
    }
    int sum=0;
    int max=0;
    if(isdigit(s[0])&&s[0]!='0')sum=1;
    for(int i=1;i<=lens;i++){
        if(isdigit(s[i]))sum=sum+1;
        if(isalpha(s[i-1])&&s[i]=='0')sum=sum-1;
        if(s[i-1]=='0'&&s[i]=='0')sum=sum-1;
        if(isalpha(s[i])) sum=0;
        if(sum>max)max=sum;
    }
    printf("%d",max);
    return 0;
}
