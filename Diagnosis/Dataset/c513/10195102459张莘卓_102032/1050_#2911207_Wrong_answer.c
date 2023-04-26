#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d",&T);
    getchar();
    for(int j=0; j<T; ++j) {
        char s1[81], s2[81], s[81];
        gets(s1); gets(s2); gets(s);
        char *p1 = strstr(s, s1);
        char *p2=NULL, *t =  &s[0];
        while(t && strstr(t, s2)) {
            p2 = strstr(t, s2);
            t = strstr(t, s2) + strlen(s2);
        }
        printf("case #%d:\n",j);
        if(p1==NULL || p2==NULL)
            printf("0\n");
        else{
            p1 += strlen(s1);
            if(p1 > p2) printf("0\n");
            else printf("%d\n",(int)(p2-p1));
        }
    }
    return 0;
}
