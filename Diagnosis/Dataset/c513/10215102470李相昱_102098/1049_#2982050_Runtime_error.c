#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct {
    char s[501];
}string;
int cmp(const void *p1,const void *p2){
    string *a = (string *)p1;
    string *b = (string *)p2;
    return strcmp(a->s,b->s);
}
string a[501];
int fun1(int p,char *s1){
    int j=0,len=0;
    int len2=strlen(s1);
    for(;j< len2;j++){
        if(!isalpha(s1[j])){
            strncpy(a[p].s,s1+j-len,len);
            a[p].s[j] = 0;
            p++;
            len=0;
        }else{
            len++;
        }
    }
    if(len){
        strncpy(a[p].s,s1+j-len,len);
        p++;
    }
    return p;
}

int main() {
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        char s1[50];
        int p=0;
        char c;
        while(scanf("%s",s1)){
            if(strstr(s1,",")||strstr(s1,"?")||
            strstr(s1,"!")||strstr(s1,"."))
            {
                p =fun1(p,s1);
            }
            else{
                strcpy(a[p].s,s1);
                p++;
            }
            c = getchar();
            if(c=='\n'){
                break;
            }
        }
        qsort(a,p,sizeof(string),cmp);
        printf("case #%d:\n",i);
        printf("%s",a[0].s);
        for(int q=1;q<p;q++){
            if(strcmp(a[q].s,a[q-1].s)!=0){
                printf(" %s",a[q].s);
            }
        }
        printf("\n");
        memset(a,0,sizeof(a));
    }
    return 0;
}
