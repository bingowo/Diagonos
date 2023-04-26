#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct data{
char c;
};

int cmp(const void* a,const void* b){
    struct data m=*(struct data*)a;
    struct data n=*(struct data*)b;
    int x=(int)m.c;
    int y=(int)n.c;
    return x>=y;
}

int main(){
    int T;
    scanf("%d",&T);
    char c=getchar();
    for(int t=0;t<T;t++){
        char s[210];
        gets(s);
        struct data ss[210];
        int len=0;
        for(int i=0;i<strlen(s);i++){
            if(isupper(s[i])){
                ss[len].c=s[i];
                len++;
            }
        }
        qsort(ss,len,sizeof(ss[0]),cmp);
        printf("case #%d:\n",t);
        int index=0;
        for(int i=0;i<strlen(s);i++){
            if(isupper(s[i])){
                printf("%c",ss[index].c);
                index++;
            }
            else printf("%c",s[i]);
        }
        printf("\n");
    }
    return 0;
}
