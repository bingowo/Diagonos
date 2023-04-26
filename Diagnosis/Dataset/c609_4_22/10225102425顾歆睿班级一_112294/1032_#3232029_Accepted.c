#include<stdio.h>
#include<string.h>
int main()
{
    char s[50];
    int max=1;
    scanf("%s",s);
    if(strlen(s)==1);
    else{
            for(int i=1,j=1;i<strlen(s);i++){
                if(s[i-1]!=s[i]){
                        j++;
                        if(i==strlen(s)-1)max=j;
                }
                else{
                    max=(max>j)?max:j;
                    j=1;
                }
            }
    }
    printf("%d",max);
    return 0;
}