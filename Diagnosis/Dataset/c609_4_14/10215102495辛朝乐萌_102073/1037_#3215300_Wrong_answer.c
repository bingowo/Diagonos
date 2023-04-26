#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


int main()
{
    char s[1000001];
    scanf("%s",s);
   int start,len=0;
   int m[128];
    for (int i = 0; i < 128; ++i) {
        m[i]=-1;
    }
    int t=0;
    char c;
    for (int i = 0; s[i]; i++) {
        c=s[i];
        if (m[c]>t){
            t=m[c]+1;
            m[c]=i;
        } else{
            m[c]=i;
            if (len<i-t+1){
                start=t;
                len=i-t+1;
            }
        }
    }
    for (int i = 0; i < len; i++) {
        printf("%c",s[start+i]);
    }
    
    return 0;
}