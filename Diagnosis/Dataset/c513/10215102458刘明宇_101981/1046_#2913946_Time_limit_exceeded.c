#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d",&T);
    int cnt = 0;
    getchar();
    while(T-->0){
        char s[100];
        gets(s);
        printf("%s\n",s);
        int sum = 0;
        char *p = s;
        while(*p++){
            if('A' <= *p && *p <= 'Z') *p = *p + 32;
            if(isspace(*p)) sum++;
            if(*p == 't' && isspace(*(--p))){
                char *p1 = p+1;//变回原来的p了
                if(*p1++ == 'h' && *p1++ == 'e'&& (*p1)&& isspace(*p1++)) sum--;
            }
            if(*p == 'a'){
                char *p1 = p+1;
                char *p2 = p-1;
                if((isspace(*p2)) && isspace(*p1)) sum--;
            }
            if(*p == 'a'){
                char *p1 = p+1;
                char *p2 = p-1;
                if(isspace(*p2) && *p1 == 'n' && isspace(*p1++) && (*p1)) sum--;
            }
            if(*p == 'o'){
                char *p1 = p+1;
                char *p2 = p-1;
                if(isspace(*p2) && *p1 == 'f' && isspace(*p1++)) sum--;
            }
            if(*p == 'f'){
                char *p1 = p+1;
                char *p2 = p-1;
                if((isspace(*p2)) && *p1 == 'o' && *p1++ == 'r' && isspace(*p1++)) sum--;
            }
            if(*p == 'a'){
                char *p1 = p+1;
                char *p2 = p-1;
                if((isspace(*p2)) && *p1 == 'n' && *p1++ == 'd' && isspace(*p1++)) sum--;
            }
        }
        printf("case #%d:\n", cnt);
        printf("%d\n",sum+1);
        cnt++;
}
}


