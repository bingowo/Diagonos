#include<stdio.h>
#include<string.h>
int main()
{
    char s[50];
    int m=1,max;
    scanf("%s",s);
    for(int i=0,j=1;i<strlen(s);i++){
        if(strlen(s)==1){
            max=1;
            break;
        }
        if(s[i]!=s[i+1])j++;
        else{
            max=(m>j)?m:j;
            m=max;
            j=1;
        }
    }
    printf("%d",max);
    return 0;
}