#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse(char* s)
{
    int len = 0;
    char* p = s;
    while (*p != 0)
    {
        len++;
        p++;
    }
    int i = 0;
    char c;
    while (i <= len / 2 - 1)
    {
        c = *(s + i);
        *(s + i) = *(s + len - 1 - i);
        *(s + len - 1 - i) = c;
        i++;
    }
}

int main() {
    int T;
    char s1[81],s2[81],s[81];
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%s %s %s",s1,s2,s);
        int len1= strlen(s1);
        int len2= strlen(s2);
        int len= strlen(s);
        printf("case #%d:\n",i);
        if(strstr(s,s1)==NULL || strstr(s,s2)==NULL)
            printf("0\n");
        else{
            char *p1=strstr(s,s1);
            char *p3= strstr(s,s2);
            reverse(s);
            reverse(s1);
            reverse(s2);
            char *p2= strstr(s,s2);
            char *p4= strstr(s,s1);
            int distance1= abs(p1-p2);
            int distance2=abs(p3-p4);
            int result=distance1<distance2?distance1:distance2;
            printf("%d\n",len-result-len1-len2>0?len-result-len1-len2:0);
        }
    }
    return 0;
}
