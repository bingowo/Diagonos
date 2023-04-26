#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[1000000];

int main(){
    int table[1000];
    scanf("%s",s);
    int l = 0, r = 0;
    int l1 = 0, r1 = 0;
    memset(table, -1, sizeof(table));
    int len = strlen(s);
    for(; r1 < len; r1++){
        if( (r - l) < (r1 - l1 - 1)){
            l = l1;
            r = r1 - 1;
        }
        if (table[s[r1]] == -1)
            table[s[r1]] = 1;
        else{
            while(s[l1] != s[r1]){
                table[s[l1]] = -1;
                l1++;
            }
            l1++;
        }
    }

    if((r-l)<(r1-l1-1)) {
        l = l1;
        r = r1 - 1;
    }
    for(int i=l;i<=r;i++)
        printf("%c",s[i]);
    return 0;
}