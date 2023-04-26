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
    return b-a;
}

int exchange(char s[])
{
    int len= strlen(s);
    int res=0;
    int a[len],b[len];
    for (int i = 0; i < len; ++i) {
        a[i]='s[i]';
        b[i]='s[i]';
    }
    qsort(b,len,sizeof(b[0]),cmp);
    for (int i = 0; i < len; ++i) {
        printf("%d %d\n",a[i],b[i]);
    }
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
    for (int i = 0; i < res-1; ++i) {
        printf("%c%c",s[i],s[i]);
    }
    for (int i = res-1; i < strlen(s); ++i) {
        printf("%c",s[i]);
    }
    return 0;
}