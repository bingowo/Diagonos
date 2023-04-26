#include <stdio.h>

int main(void) {
    int t;
    scanf("%d",&t);
    for (int i=0; i<t; i++) {
        char s[510];
        scanf("%s",s);
        char *p1=s,*p2 =s;
        int length = 0;
        printf("case #%d:\n",i);
        while (*p2) {
            if(*p2!=*p1 || length==255){
                printf("%d%c",length,*p1);
                length=0;
                p1=p2;
            }
            else{
                length++;
                p2++;
            }
        }
        if (length!=0) {
            printf("%d%c\n",length,*p1);
        }
        else{
            printf("\n");
        }
    }
    return 0;
}
