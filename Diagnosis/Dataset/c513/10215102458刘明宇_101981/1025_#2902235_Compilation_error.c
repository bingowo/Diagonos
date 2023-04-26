#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct data{
    char str[200];
    int difs;
};

int cnt_dif(char *s)
{
    int len = strlen(s);
    int a[1000];
    for(int i = 0;i<1000;i++){
        a[i] = -1;
    }
    int sum = 1;
    char *p = s;
    a[*p] = 0;
    while(*++p){
        if(a[*p] == -1){
            a[*p] = 0;
            sum++;
        }
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



}
