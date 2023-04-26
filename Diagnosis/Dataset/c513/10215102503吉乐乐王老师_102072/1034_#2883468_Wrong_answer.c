#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
double order[26];
int cmp(const void *a,const void *b){
    char x=*(char*)a;
    char y=*(char*)b;
    if(tolower(x)==tolower(y)){
        return y-x;
    }
    return order[tolower(x)-'a']>order[tolower(y)-'a']?1:-1;
}
int main(){
    int t;scanf("%d",&t);getchar();
    int cas=0;
    while(t--){
        for(int i=0;i<26;i++)scanf("%lf",&order[i]);
        getchar();
        char s[1000];char ch=getchar();int slen=0;
        while(ch!='\n'){
            s[slen]=ch;ch=getchar();slen++;
        }
        qsort(s,slen,sizeof(char),cmp);
        printf("case #%d:\n",cas++);
        for(int i=0;i<slen;i++)putchar(s[i]);
        putchar('\n');
    }
}