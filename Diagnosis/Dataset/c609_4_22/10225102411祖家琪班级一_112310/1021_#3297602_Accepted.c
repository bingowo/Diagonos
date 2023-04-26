#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int findch(char *s,char c)
{
    if(c >= 97) c -= 32;
    int l = strlen(s);
    for(int i=0;i<l;i++){
        if(s[i] == c) return i;
    }
    return -1;
}
int cmp(const void *a,const void *b)
{
    typedef struct
    {
        char s1[21];
        char s2[21];
    }pair;
    pair *pa = (pair *)a;
    pair *pb = (pair *)b;
    return strcmp(pa->s2,pb->s2);
}
int main()
{
    //*
    char table[27];
    while(scanf("%s",table) != EOF){
        struct pair
        {
            char s1[21];
            char s2[21];//根据字典序转换后的待排字符串
        };
        struct pair strd[100];
        char c;
        int cnt = 0;
        do{
            scanf("%s",strd[cnt].s1);
            memset(strd[cnt++].s2,0,21);
        }while(c = getchar() == ' ');
        for(int i=0;i<cnt;i++){
            int l = strlen(strd[i].s1);
            for(int j=0;j<l;j++){
                strd[i].s2[j] = findch(table,strd[i].s1[j]) + 65;
            }
            //printf("%s %s\n",strd[i].s1,strd[i].s2);
        }
        qsort(strd,cnt,42,cmp);
        for(int i=0;i<cnt;i++){
            printf("%s%c",strd[i].s1,(i == cnt-1)?'\n':' ');
        }
    }
    return 0;
}