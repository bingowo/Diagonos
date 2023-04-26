#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int cmp(const void *a,const void *b)
{
    int *m,*n;
    m=(int *)a;
    n=(int *)b;
    return a-b;
}

int exchange(char s[])
{
    int len= strlen(s);
    int res=0;
    int a[len],b[len];
    for (int i = 0; i < len; ++i) {
        a[len]='s[i]'-'A';
        b[len]='s[i]'-'A';
    }
    qsort(b,len,sizeof(b[0]),cmp);
    for(int i=0;i<len;i++){
        if(a[i]==b[i]) res++;
        else break;
    }
    return res;
}

int main(void)
{
    char s[10000];
    scanf("%s",s);
    int res= exchange(s);
    for (int i = 0; i < res; ++i) {
        printf("%c%c",s[i],s[i]);
    }
    for (int i = res; i < strlen(s); ++i) {
        printf("%c",s[i]);
    }
    return 0;
}