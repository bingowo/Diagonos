#include <stdio.h>
#include <string.h>
typedef struct {
    int exist;
    int pos;
    int alb;
}al;
int main() {
    char s[1000001];
    scanf("%s",s);
    int sign =0;
    int len =1;
    int len1=0;
    al a[127] = {{0,0}};
    for(int i=0;i< strlen(s);i++)
    {
        if (a[s[i]].exist==0){
            a[s[i]].exist =1;
            a[s[i]].pos =i;
            len1++;
        }
        else{
            if(len1>len){
                len = len1;
                sign = i-len1+1;
            }
            int j=a[s[i]].pos;
            len1 = 0;
            a[s[i]].pos = i;
            i =j+1;
            memset(a,0, sizeof(a));
        }
    }
    s[sign+len]=0;
    printf("%s\n",s+sign);
    return 0;
}
