#include<stdio.h>
#include<string.h>
int main()
{
    char s[51];
    scanf("%s",s);
    int len=strlen(s);
    len=len/2;
    int sum=0;
    for(int i=len;i>=0;i--){
        if(sum=0){
            if(s[i]=='(')sum++;
            else sum++;
        }
        if(s[i]=='(')sum*=2;
        else{
            sum++;
            if(s[i-1]=='(')sum++,i--;
        }
    }
    printf("%d",sum);
    return 0;
}