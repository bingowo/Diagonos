#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
int a[27];
typedef struct {
    char string[21];
    int len;
}str;
int cmp(const void *p1,const void *p2){
    str *a1=(str *)p1;
    str *b1=(str *)p2;
    int len=a1->len<b1->len?a1->len:b1->len;
    for(int p=0;p<len;p++){
        char c1='A',c2='A';
        if(islower(a1->string[p])){
            c1='a';
        }
        if(islower(b1->string[p])){
            c2='a';
        }
        if(a[a1->string[p]-c1]!=a[b1->string[p]-c2]){
            return a[a1->string[p]-c1]-a[b1->string[p]-c2];
        }
    }
    return a1->len-b1->len;
}
int main() {
    char s[27];
    scanf("%s",s);
    do{
        str b[100];
        for(int i =0;i<26;i++){
            a[s[i]-'A']=i;
        }
        char c;
        int j=0;
        do{
            scanf("%s",b[j].string);
            b[j].len = strlen(b[j].string);
            j++;
            c=getchar();
        } while (c!='\n');
        qsort(b,j,sizeof(b[0]),cmp);
        for(int m=0;m<j;m++){
            printf("%s%c",b[m].string,m==j-1?'\n':' ');
        }
    }while (scanf("%s",s)!=EOF);
    return 0;
}
