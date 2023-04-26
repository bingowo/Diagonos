#include<stdio.h>
int main()
{
    char s[50],a[50];
    int m=1,max;
    scanf("%s",s);
    for(int i=0,j=1,k=0;i<strlen(s);i++){
        if(s[i]!=s[i+1])j++;
        else{
            max=(m>j)?m:j;
        }
    }
    printf("%d",max);
    return 0;
}

