#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{   char s[70];
    scanf("%s",&s);
    int l,i,max=0,count=1;
    l=strlen(s);
    for(i=0;i<l;i++){
        if(s[i+1] && s[i]!=s[i+1]) count++;
        else{
            if(count>max) max=count;
            count=1;
        }
    }
    printf("%d",max);
    return 0;
}