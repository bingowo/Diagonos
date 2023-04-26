#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>


int main()
{
    int t;
    scanf("%d",&t);
    char c = getchar();
    for (int i=0; i<t; i++) {
        int Alpha[26]={0},index =0;
        char s[210];
        gets(s);
        char *p=s;
        while (*p) {
            if(isalpha(*p)){
                Alpha[*p-'A']+=1;
            }
            p++;
        }
        p=s;
        printf("case #%d:\n",i);
        for (; Alpha[index] == 0; index++);
        while (*p) {
            if(isalpha(*p)){
                *p = index+'A';
                 Alpha[index]--;
                for (; Alpha[index] == 0; index++);
            }
        p++;
        }
        printf("%s\n",s);
}
    return 0;
}
