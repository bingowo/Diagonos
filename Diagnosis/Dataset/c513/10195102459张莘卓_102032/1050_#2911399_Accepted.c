#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* strrstr(char*s, int len, char* t){
    for(int i=len-1; i>=0; --i)
        if(strstr(&s[i], t)){
            return s + i;
        }
    return NULL;
}

int main()
{
    int T;
    scanf("%d",&T);
    getchar();
    for(int j=0; j<T; ++j) {
        char s1[81], s2[81], s[81];
        gets(s1); gets(s2); gets(s);
        int l1=0, l2=0;
        char *p1 = strstr(s, s1);
        char *p2 = strrstr(s,strlen(s),s2);
        if(p1 && p2) {
            if(p1 > p2){
                p2 += strlen(s2);
                if(p2 > p1) l1 = 0;
                else l1 = (int)(p1 - p2);
            }else {
                p1 += strlen(s1);
                if(p1 > p2) l1 = 0;
                else l1 = (int)(p2 - p1);
            }
        }else l1 = 0;
        
        p1 = strrstr(s, strlen(s), s1);
        p2 = strstr(s, s2);
        if(p1 && p2){
            if(p1 > p2){
                p2 += strlen(s2);
                if(p2 > p1) l2 = 0;
                else l2 = (int)(p1 - p2);
            }else {
                p1 += strlen(s1);
                if(p1 > p2) l2 = 0;
                else l2 = (int)(p2 - p1);
            }
        }else l2 = 0;
        printf("case #%d:\n%d\n",j,l1>l2?l1:l2);
    }
    return 0;
}
