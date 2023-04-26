#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

char a[26];
int table[128];

int min(int a,int b){
    return a > b ? b : a;
}

int cmp(const void *a,const void *b){
    char *s1,*s2;
    s1 = *(char (*)[20])a;
    s2 = *(char (*)[20])b;
    int len1,len2;
    len1 = strlen(s1);
    len2 = strlen(s2);
    int len = min(len1,len2);
    for(int i = 0;i < len;i++){
        char m,n;
        m = toupper(*s1);
        n = toupper(*s2);
        if(m == n) s1++,s2++;
        else return table[*s1] - table[*s2];
    }
}

int main(){
    while(scanf("%s",a) != EOF){
        for(int t = 0;t < 26;t++){
            table[a[t]] = t;
        }
        char s[100][20];
        int i = 0;
        while(scanf("%s",s[i]) != EOF) i++;
        qsort(s,i,sizeof(s[0]),cmp);
        for(int t = 0;t < i-1;t++) printf("%s ",s[t]);
        printf("%s\n",s[i-1]);
    }
}