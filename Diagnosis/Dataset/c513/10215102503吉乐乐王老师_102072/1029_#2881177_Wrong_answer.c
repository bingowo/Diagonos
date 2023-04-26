#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int cmp(const void*a,const void *b){
    char x=*(char*)a;
    char y=*(char*)b;
    if(isalpha(x)&&isalpha(y))return x>y?1:-1;
    return 0;
}
int main(){
    int t;scanf("%d",&t);getchar();
    int idx=0;
    while(t--){
        char s[205];
        scanf("%s",s);getchar();
        qsort(s,strlen(s),sizeof(char),cmp);
        printf("case #%d:\n%s\n",idx++,s);
    }
}