#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
double order[26];
int cmp(const void *a,const void *b){
    char x=*(char*)a;
    char y=*(char*)b;
    if(fabs(tolower(x)-tolower(y))<1e-8){
        return y-x;
    }
    else if(fabs(order[tolower(y)-'a']-order[tolower(x)-'a']<1e-8){
        return x-y;
    }
    return order[tolower(y)-'a']>order[tolower(x)-'a']?1:-1;
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