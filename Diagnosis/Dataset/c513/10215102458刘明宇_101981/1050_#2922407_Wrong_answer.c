#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int T;
    scanf("%d",&T);
    int cnt = 0;
    getchar();
    while(T-->0){
        char s1[81],s2[81],s[81];
        gets(s1);
        gets(s2);
        gets(s);
        int flag = 0;
        if(strstr(s,s1) == NULL) flag = 1;
        if(strstr(s,s2) == NULL) flag = 1;
        if(strcmp(s1,s2) == 0) flag = 1;
        char *p1 = strstr(s,s1);
        int len1 = strlen(s1);
        p1 = p1 + len1;
        //printf("%s",s1);
        //printf("%s",s2);
        int len2 = strlen(s2);
        char *p2 = s2;
        while(*p2){
            p2++;
        }
        p2 = p2 - 1;//p2指向S2的最后一个字符
        char *p3 = s;
        char *p4 = s;//p4指向s的第一个字符
        while(*p3){
            p3++;
        }
        p3 = p3 - 1;//p3指向S的最后一个字符
        //int len3 = strlen(s);
        while(*p3 != *p4){
            if(*p3 == *p2){
                int sum = 0;
                for(int i = 0;i < len2;i++){
                    char *p5 = p3-i;
                    char *p6 = p2-i;
                    if(*p5 == *p6){
                        sum++;
                    }
                }
                if(sum == len2) {sum = 0;break;}
            }
            p3--;
        }
        p3 = p3 - len2+1;
        int gap = p3 - p1;
        if(flag == 1){
            printf("case #%d:\n",cnt);
            printf("0\n");
        }
        else{
            printf("case #%d:\n",cnt);
            printf("%d\n",gap);
        }
         cnt++;

    }
}