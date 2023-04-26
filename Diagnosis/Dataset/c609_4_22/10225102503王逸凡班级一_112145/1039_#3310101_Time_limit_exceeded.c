#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

char *strrstr(char *s1,char* s2){
    char *p = NULL;
    p = strstr(s1,s2);
    char *p1 = p+strlen(s2);
    while(strstr(p1,s2)!=NULL){
    p = strstr(p1,s2);
    *p1 = p+strlen(s2);
    }

    return p;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int cnt = 0;cnt<T;cnt++){
        char s1[81];
        char s2[81];
        char s[81];
        scanf("%s",s1);
        scanf("%s",s2);
        scanf("%s",s);
        char *p1,*p2;
        p1 = strstr(s,s1);
        p2 = strrstr(s,s2);
        int len = p2-p1-strlen(s1);
        if(p1!=NULL&&p2!=NULL){
            printf("case #%d:\n%d",cnt,len);
        }

        }
    return 0;
}
