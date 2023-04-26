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
        char *p1 = strstr(s, s1), *p2=NULL;
        for(int i=strlen(s)-1; i>=0; --i)
            if(strstr(&s[i], s2)){
                p2 = i + &s[0];
                break;
            }
        printf("case #%d:\n",j);
        if(p1==NULL || p2==NULL)
            printf("0\n");
        else{
            if(p1 > p2) {
                p2 += strlen(s2);
                if(p2 > p1) printf("0\n");
                else
                    printf("%d\n",(int)(p1-p2));
            }else{
                p1 += strlen(s1);
                if(p1 > p2) printf("0\n");
                else printf("%d\n",(int)(p2-p1));
            }
        }
    }
    return 0;
}
