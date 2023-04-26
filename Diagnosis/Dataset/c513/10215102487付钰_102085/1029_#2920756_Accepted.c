#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int cmp(const void *p1,const void *p2){
    const char *a=(const char *)p1;
    const char *b=(const char *)p2;
    return strcmp(a,b);
}
int main() {
    int T;
    scanf("%d",&T);
    getchar();
    for(int i =0;i<T;i++){
        //getchar();
        char s[201];
        char alphabet[201]={0};
        int el[201]={0};
        int d=0;
        while ((s[d++]=getchar())&&(s[d-1]!='\n'));
        s[d] = 0;
        int len=strlen(s);
        int p=0;
        for(int j=0;j<len;j++){
            if(isalpha(s[j])){
                alphabet[p++]=s[j];
            }else{
                el[j]=1;
            }
        }
        qsort(alphabet,p, sizeof(char),cmp);
        printf("case #%d:\n",i);
        int m=0;
        for (int q=0;q<len;q++){
            if(el[q]){
                printf("%c",s[q]);
            } else{
                printf("%c",alphabet[m++]);
            }
        }
    }
    return 0;
}