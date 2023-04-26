#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void*a, const void*b)
{
    char *p1=(char*)a, *p2=(char*)b;
    return *p1-*p2;
}
int main()
{
    int T, I;
    scanf("%d",&T);
    for(I=0; I<T; I++)
    {
        char s[25], store[20];
        int i, j, cnt=0, l;
        scanf("%s",s+1);
        s[0]='0';
        l=strlen(s);
        for(i=l-1; i+1; i--) if(s[i]>s[i-1]) break;
        for(j=l-1; j>=i; j--) store[cnt++]=s[j];
        qsort(store, cnt, sizeof(char), cmp);
        for(j=0; j<cnt; j++) if(store[j]>s[i-1]) break;
        s[i-1]^=store[j];
        store[j]^=s[i-1];
        s[i-1]^=store[j];
        qsort(store, cnt, sizeof(char), cmp);
        for(j=0; j<i; j++) if(s[j]!='0') break;
        printf("case #%d:\n",I);
        for(; j<i; j++) printf("%c",s[j]);
        for(j=0; j<cnt; j++) printf("%c",store[j]);
        printf("\n");
    }
    return 0;
}