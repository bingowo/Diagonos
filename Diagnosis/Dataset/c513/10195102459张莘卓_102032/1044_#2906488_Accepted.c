#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int islegal(char *p) {
    if(p == NULL) return 0;
    if(*p >= '0' && *p <= '9') return 1;
    if(*p >= 'a' && *p <= 'f') return 1;
    return 0;
}

char* find(char* s) {
    char* p;
    int flag = 0;
    do {
        p = strstr(s, "0x");
        if(p==NULL || *(p+2)=='\0')
            return NULL;
        if(islegal(p+2)) flag = 1;
        else  s = p + 2;
    }while(flag == 0);
    return p+2;
}

int main()
{
    char t[100001];
    scanf("%s",t);
    char *s = &t[0];
    char* p = find(s);
    if(p == NULL) printf("-1");
    else{
        int cnt = 0;
        do{
            char *end = p;
            while(islegal(end+1)) ++end;
            unsigned n = 0;
            while(p <= end){
                int plus = isalpha(*p) ? *p-'a'+10 : *p-'0';
                n = n * 16 + plus;
                ++p;
            }
            if(cnt++) printf(" ");
            printf("%u",n);
            s = end + 1;
            p = find(s);
        }while(p);
    }
    printf("\n");
    return 0;
}
