#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s[1000][1000];


int main()
{
    memset(s,0,1000*1000*sizeof(char));
    int cnt = 0;
    while(gets(s[cnt])!=NULL){
        cnt++;
    }
    
    
    for(int i = 0;i<cnt;i++){
        if(i == cnt-1){
            printf("%s",s[i]);
            break;
        }
        printf("%s\n",s[i]);

    }
    return 0;
}
