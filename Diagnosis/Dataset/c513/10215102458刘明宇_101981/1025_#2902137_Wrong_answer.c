#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct data{
    char str[21];
    int difs;
};

int cnt_dif(char *s)
{
    int len = strlen(s);
    int sum = 0;
    for(int i = 0;i < len;i++){
        for(int j = i + 1;j<len;j++){
            if(s[j] == s[i]){
                s[j] = 0;
            }
        }
    }
    for(int i = 0;i < len;i++){
        if(s[i] != 0) sum++;
    }
    return sum;
}

int cmp(const void*a,const void *b)
{
    struct data p1,p2;
    p1 = *((struct data*)a);
    p2 = *((struct data*)b);
    p1.difs = cnt_dif(p1.str);
    p2.difs = cnt_dif(p2.str);
    if(p1.difs == p2.difs) return strcmp(p1.str,p2.str);
    else{
        return p2.difs - p1.difs;
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    int cnt = 0;
    while (T-->0)
    {
        int n;
        scanf("%d",&n);
        char s;
        struct data p[101];
        for(int i =0;i<n;i++){
            scanf("%s",p[i].str);
        }
        qsort(p,n,sizeof(p[0]),cmp);
        printf("case #%d:\n",cnt);
        for(int i =0;i < n;i++){
            printf("%s\n",p[i].str);
        }
        cnt++;
    }
}
