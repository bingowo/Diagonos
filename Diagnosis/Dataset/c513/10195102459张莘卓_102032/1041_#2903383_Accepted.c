#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[51];
    scanf("%s",s);
    int max = 0;
    for(int i=0; s[i]; ++i){
        int k = i;
        while(s[k+1] && s[k+1]!=s[k]) ++k;
        if(k-i+1 > max) max = k-i+1;
    }
    printf("%d\n",max);
    return 0;
}
