#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int cmp(const void* a,const void* b){
    int x=*(char*)a;
    int y=*(char*)b;
    return x>y;
}

int main(){
    int T;
    scanf("%d",&T);
    char c=getchar();
    for(int t=0;t<T;t++){
        char s[210];
        gets(s);
        char ss[210];
        int len=0;
        for(int i=0;i<strlen(s);i++){
            if(isupper(s[i])){
                ss[len]=s[i];
                len++;
            }
        }
        qsort(ss,strlen(ss),sizeof(ss[0]),cmp);
        printf("case #%d:\n",t);
        int index=0;
        for(int i=0;i<strlen(s);i++){
            if(isupper(s[i])){
                printf("%c",ss[index]);
                index++;
            }
            else printf("%c",s[i]);
        }
        printf("\n");
    }
    return 0;
}
