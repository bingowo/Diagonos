#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int cmp(const void*a,const void *b){
    char x=*(char*)a;
    char y=*(char*)b;
    if((x>='A'&&x<='Z')&&(y>='A'&&y<='Z'))return x-y;
    return 0;
}
int main(){
    int t;scanf("%d",&t);getchar();
    int idx=0;
    while(t--){
        char s[205];int si=0;
        char ch=getchar();
        while(ch!='\n'){
            s[si++]=ch;ch=getchar();
        }
        qsort(s,si,sizeof(char),cmp);
        printf("case #%d:\n%s\n",idx++,s);
                for(int i=0;i<si;i++){
            putchar(s[i]);
        }
        putchar('\n');
    }
}