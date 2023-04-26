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
    for(int i=0;i< strlen(s);i++)
    {
        while (a[s[i]].exist==0){
            a[s[i]].exist =1;
            a[s[i]].pos =i;
            len1++;
            i++;
        }
        if(len1>len){
            len = len1;
            sign = i-len1;
        }
        if(a[s[i]].exist){
            len1 = i-a[s[i]].pos;
            a[s[i]].pos = i;
            for(int j=0;j<127;j++){
                if(a[j].pos<=a[s[i]].pos){
                    a[j].pos = 0;
                    a[j].exist =0;
                }
            }
        }
    }
    s[sign+len]=0;
    printf("%s\n",s+sign);
    return 0;
}
