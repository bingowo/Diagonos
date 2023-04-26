#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
    char s[50];
    int a=1;
    int b;
    int max=1;
    scanf("%s",s);
    b=strlen(s);
    for(int i=0;i<b-1;i++){
        if(s[i]!=s[i+1]){
            a++;
        }
        else{
            if(a>max){
                max=a;
            }
            a=1;

        }
    }
    printf("%d",max);
    return 0;
}
