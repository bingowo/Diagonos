#include <stdio.h>
#include <string.h>
typedef struct {
    int exist;
    int pos;
}al;
int main() {
    char s[1000001];
    scanf("%s",s);
    int sign =0;
    int len =1;
    int len1=0;
    al a[127] = {{0,0}};
    int i=0;
    for(;i< strlen(s);i++)
    {
        if (a[s[i]].exist==0){
            a[s[i]].exist =1;
            a[s[i]].pos =i;
            len1++;
        }
        else{
            if(len1>len){
                len = len1;
                sign = i-len1;
            }
            i=a[s[i]].pos;
            len1 = 0;
            memset(a,0, sizeof(a));
        }
    }
    if(len1>len){
        len = len1;
        sign = i-len1;
    }
    s[sign+len]=0;
    printf("%s\n",s+sign);
    return 0;
}
