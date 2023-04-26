#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define N 100


int cmp(const void *a,const void *b)
{

}


char* insert(char* s,int pos)
{
    for (int i = strlen(s)+1; i > pos ; i--) {
        s[i]=s[i-1];
    }
    return s;
}

int main()
{
    char s[2*N+1];
    char t[2*N+1];
    scanf("%s",s);
    int len= strlen(s);
    for (int i = 0; i < len; ++i) {
        if (strcmp(insert(strcpy(t,s),i),s)<0)
            len++,i++,strcpy(s,t);
    }
    printf("%s\n",s);
    return 0;
}