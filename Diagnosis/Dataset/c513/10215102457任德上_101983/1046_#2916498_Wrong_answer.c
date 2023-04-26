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
        s[0] = ' ';
        gets(s+1);
        int sum = 0;
        char *p = s;
        char *pl = s;
        int len = strlen(s);
        while(*pl){
            pl++;
            if('A' <= *pl && *pl <= 'Z') *pl = *pl + 32;
        }
        s[len - 1] = ' ';
        while(*p){
            if('A' <= *p && *p <= 'Z') *p = *p + 32;//都切换成小写字母
            if(isspace(*p)) sum++;
            if(*p == 't'){
                char *p1 = p+1;
                char *p2 = p-1;
                char *p3 = p+2;
                char *p4 = p+3;
                if(*p1 == 'h' && *p3 == 'e' && isspace(*p2) && isspace(*p4)) sum--;
            }
            if(*p == 'a'){
                char *p1 = p+1;
                char *p2 = p-1;
                if((isspace(*p2)) && isspace(*p1)) sum--;

            }
            if(*p == 'a'){
                char *p1 = p+1;
                char *p2 = p-1;
                char *p3 = p+2;
                if(isspace(*p2) && *p1 == 'n' && isspace(*p3)) sum--;

            }
            if(*p == 'o'){
                char *p1 = p+1;
                char *p2 = p-1;
                char *p3 = p+2;
                if(isspace(*p2) && *p1 == 'f' && isspace(*p3)) sum--;

            }
            if(*p == 'f'){
                char *p1 = p+1;
                char *p2 = p-1;
                char *p3 = p+2;
                char *p4 = p+3;
                if((isspace(*p2)) && *p1 == 'o' && *p3 == 'r' && isspace(*p4)) sum--;

            }
            if(*p == 'a'){
                char *p1 = p+1;
                char *p2 = p-1;
                char *p3 = p+2;
                char *p4 = p+3;
                if((isspace(*p2)) && *p1 == 'n' && *p3 == 'd' && isspace(*p4)) sum--;
            }
            p++;
        }
        printf("case #%d:\n", cnt);
        printf("%d\n",sum-1);
        cnt++;
    }
}