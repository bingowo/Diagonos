#include <stdio.h>
#include <string.h>
#define MAXLEN 100


char* insert(char* ps,int pos)
{
    int i;
    for(i = strlen(s) + 1;i > pos;i--) s[i] = s[i - 1];
    return s;
    
}
int main()
{
    char s[2 * N + 1],t[2 * N + 1];
    int i,len;
    for(scanf("%s",s),len = strlen(s),i = 0;i < len;i++)
        if(strcmp(insert(strcpy(t,s),i),s) < 0) len ++,i++,strcpy(s,t);
    printf("%s\n",s);
    return 0;
}
